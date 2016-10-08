
#include "Game.h"
#include "MenuState.h"
#include <memory>

#include "World.h"
#include "Personnage.h"

int main()
{
	Game g;
	std::unique_ptr<State> state(std::make_unique<MenuState>(g));
	g.setState(state);
	g.run();
}