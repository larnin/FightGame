#include "SingleFightState.h"
#include "Personnage.h"
#include "Utilities.h"
#include "MenuState.h"
#include "Game.h"
#include <iostream>
#include <thread>
#include <functional>

using namespace std::placeholders;

const unsigned int maxRounds(50);

SingleFightState::SingleFightState(Game & game)
	: State(game)
	, m_world(12)
{
	clearConsole();
	timedWriter("Quel est votre nom ?", 25);
	std::cout << std::endl;
	std::string playerName;
	std::getline(std::cin, playerName);
	
	std::unique_ptr<ActionChooserFactory> fPlayer(std::make_unique<InputActionFactory>());
	Personnage player(playerName, 100, PLAYER_TEAM, m_world, fPlayer);
	player.move(1);
	m_playerObserver = std::make_unique<DeathPersonnageObserver>(player);
	m_playerObserver->setCallBack([this](auto & p) {onPersonnageDie(p); });
	m_world.addPersonnage(player);

	std::unique_ptr<ActionChooserFactory> fOpponent(std::make_unique<IAActionFactory>());
	Personnage opponent("Kevin", 75, ENNEMI_TEAM, m_world, fOpponent);
	opponent.move(10);
	m_ennemiObserver = std::make_unique<DeathPersonnageObserver>(opponent);
	m_ennemiObserver->setCallBack([this](auto & p) {onPersonnageDie(p); });
	m_world.addPersonnage(opponent);

	m_timerObserver = std::make_unique<EndTimerObserver>(m_world, maxRounds);
	m_timerObserver->setCallBack([this](auto & w) {onTimerEnd(w); });

	clearConsole();
	timedWriter("C'est partit pour un combat de " + std::to_string(maxRounds) + " rounds", 25);
}

void SingleFightState::update()
{
	m_world.update();
}

void SingleFightState::onPersonnageDie(Personnage &)
{
	World & w(m_world);
	auto ids(w.personnages());
	const Personnage &p(w.personnage(*std::find_if(ids.begin(), ids.end(), [&w](const auto & id) { return w.personnage(id).life() != 0; })));

	std::cout << std::endl << std::endl;
	timedWriter(p.name() + " remporte le combat !", 25);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	returnToMenu();
}

void SingleFightState::onTimerEnd(World &)
{
	std::cout << std::endl << std::endl;
	timedWriter("Le combat est termine, temps ecoule !", 25);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	returnToMenu();
}

void SingleFightState::returnToMenu()
{
	std::cout << std::endl;
	timedWriter("Appuyez sur [ENTRER] pour retourner au menu.", 25);
	std::cin.get();

	std::unique_ptr<State> s(std::make_unique<MenuState>(m_game));
	m_game.setState(s);
}