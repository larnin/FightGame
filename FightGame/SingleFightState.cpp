#include "SingleFightState.h"
#include "Personnage.h"
#include "Utilities.h"
#include <iostream>

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
	m_world.addPersonnage(player);

	std::unique_ptr<ActionChooserFactory> fOpponent(std::make_unique<IAActionFactory>());
	Personnage opponent("Kevin", 75, ENNEMI_TEAM, m_world, fOpponent);
	opponent.move(10);
	m_world.addPersonnage(opponent);

	clearConsole();
}

void SingleFightState::update()
{
	m_world.update();
}