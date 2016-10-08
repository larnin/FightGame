#pragma once

#include "Comportement.h"

class ComportementState
{
public:
	ComportementState(Comportement & c)
		: m_comportement(c)
	{ }

	ComportementState(const ComportementState &) = delete;
	ComportementState & operator=(const ComportementState &) = delete;
	virtual ~ComportementState() = default;

	virtual void update() = 0;

protected:
	Comportement & m_comportement;
};