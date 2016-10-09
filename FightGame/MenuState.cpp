#include "MenuState.h"
#include "SingleFightState.h"
#include "AdventureState.h"
#include "MenuCommand.h"
#include "Utilities.h"
#include <iostream>
#include <map>
#include <limits>

MenuState::MenuState(Game & game)
	: State(game)
{
}

void MenuState::update()
{
	clearConsole();

	int choosenMode(-1);
	std::map<int, std::unique_ptr<MenuCommand>> validModes;
	validModes.emplace(0, std::make_unique<ExitCommand>(*this));
	validModes.emplace(2, std::make_unique<RunAdventureCommand>(*this));
	validModes.emplace(1, std::make_unique<RunSingleFightCommand>(*this));

	timedWriter("Bienvenue dans le super jeu de combat console !\n", 25);
	
	do
	{
		timedWriter("Que voulez vous faire ?", 25);
		timedWriter("\t[1] Combat rapide", 25);
		timedWriter("\t[2] Aventure", 25);
		timedWriter("\t[0] Quitter", 25);
		std::cin >> choosenMode;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (validModes.find(choosenMode) == validModes.end());

	validModes[choosenMode]->execute();
}

void MenuState::runAdventure()
{
	std::unique_ptr<State> s(std::make_unique<AdventureState>(m_game));
	m_game.setState(s);
}

void MenuState::runSingleFight()
{
	std::unique_ptr<State> s(std::make_unique<SingleFightState>(m_game));
	m_game.setState(s);
}

void MenuState::exit()
{
    std::unique_ptr<State> s;
    m_game.setState(s);
}
