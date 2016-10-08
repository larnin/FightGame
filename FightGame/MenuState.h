#pragma once

#include "State.h"

class MenuState : public State
{
public:
	MenuState(Game & game);
	virtual ~MenuState() = default;

	virtual void update() override;

	void runAdventure();
	void runSingleFight();
	void exit();
};

