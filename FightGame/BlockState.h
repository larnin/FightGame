#pragma once

#include "ComportementState.h"

class BlockState : public ComportementState
{
public:
	BlockState(Comportement & c, unsigned int time);
	virtual ~BlockState() = default;

	virtual void update() override;

private:
	unsigned int m_time;
};

