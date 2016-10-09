#pragma once

#include "PersonnageCommand.h"

class MoveCommand : public PersonnageCommand
{
public:
	MoveCommand(Comportement & c);
	virtual ~MoveCommand() = default;

	virtual void execute(const std::string & param) override;
	virtual void help() const override;
};

