#pragma once

#include "PersonnageCommand.h"

class ChargeCommand : public PersonnageCommand
{
public:
	ChargeCommand(Comportement & c);
	virtual ~ChargeCommand() = default;

	virtual void execute(const std::string & param) override;
	virtual void help() const override;
};

