#include "AdventureState.h"
#include "MenuState.h"
#include <iostream>
#include <thread> 

#include "Utilities.h"

AdventureState::AdventureState(Game & g)
	: State(g)
{
}

void AdventureState::update()
{
	clearConsole();
	timedWriter("Bienvenue a la taverne l'auberge IN jeune voyageur.", 25);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	timedWriter("Vous cherchez une mission pour poursuivre votre aventure ?", 25);
	std::cout << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	timedWriter("Allez faire un combat rapide, je n'ai rien à vous proposer ici !", 25);
	std::this_thread::sleep_for(std::chrono::seconds(2));

	std::unique_ptr<State> s(std::make_unique<MenuState>(m_game));
	m_game.setState(s);
}