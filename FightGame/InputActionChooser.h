#pragma once

#include "NextActionChooser.h"
#include "CommandList.h"

class InputActionChooser : public NextActionChooser
{
public:
	InputActionChooser(Comportement & c);
	virtual ~InputActionChooser() = default;

	virtual void update() override;

private:
	CommandList m_commands;
};

