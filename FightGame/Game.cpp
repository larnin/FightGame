#include "Game.h"
#include "State.h"

void Game::run()
{
	while (m_current)
	{
		m_current->update();
	}
}

void Game::setState(std::unique_ptr<State> & state)
{
	m_current = std::move(state);
}