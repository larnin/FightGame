#pragma once

#include "State.h"

class SingleFightState : public State
{
public:
	SingleFightState(Game & game);
	virtual ~SingleFightState() = default;

	virtual void update() override;
};

