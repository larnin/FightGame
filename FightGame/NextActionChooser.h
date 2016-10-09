#pragma once

#include "ComportementState.h"

class NextActionChooser : public ComportementState
{
public:
	NextActionChooser(Comportement & c)
		: ComportementState(c)
	{ }
	virtual ~NextActionChooser() = default;
};