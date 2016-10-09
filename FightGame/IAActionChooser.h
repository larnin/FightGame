#pragma once

#include "NextActionChooser.h"
#include <memory>

enum StateType
{
	ATTACK_STATE,
	BLOCK_STATE,
	MOVE_STATE,
	WAIT_STATE,
	CHARGE_STATE
};

std::unique_ptr<ComportementState> createState(StateType type, Comportement & c);

class IAActionChooser : public NextActionChooser
{
public:
	IAActionChooser(Comportement & c)
		: NextActionChooser(c)
	{}
	virtual ~IAActionChooser() = default;

	virtual void update() override;
};

