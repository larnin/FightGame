#pragma once

#include "State.h"
#include "World.h"

class SingleFightState : public State
{
public:
	SingleFightState(Game & game);
	virtual ~SingleFightState() = default;

	virtual void update() override;

private:
	World m_world;
};

