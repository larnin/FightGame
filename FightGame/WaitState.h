#pragma once

#include "ComportementState.h"

class WaitState : public ComportementState
{
public:
	WaitState(Comportement & c, unsigned int time);
	virtual ~WaitState() = default;

	virtual void update() override;

private:
	unsigned int m_time;
	bool m_messageFired;
};

