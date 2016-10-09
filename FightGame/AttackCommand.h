#pragma once

#include "PersonnageCommand.h"
#include "Attack.h"

class AttackCommand : public PersonnageCommand
{
public:
	AttackCommand(Comportement & c);
	virtual ~AttackCommand() = default;

	virtual void execute(const std::string & param) override;
	virtual void help() const override;
};

