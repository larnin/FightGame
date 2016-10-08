#pragma once

#include "State.h"

class AdventureState : public State
{
public:
	AdventureState(Game & g);
	virtual ~AdventureState() = default;

	virtual void update() override;
};

