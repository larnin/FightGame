#pragma once

#include "Game.h"

class State
{
public:
	State(Game & game);
	virtual ~State() = default;
	virtual void update() = 0;

protected:
	Game & m_game;
};

