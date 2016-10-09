#pragma once

#include "ComportementState.h"

class MoveState : public ComportementState
{
public:
	MoveState(Comportement & c, int dir);
	virtual ~MoveState() = default;

	virtual void update() override;

private:
	int m_move;
};

