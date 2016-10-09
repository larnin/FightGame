#pragma once

#include "PersonnageCommand.h"

class BlockCommand : public PersonnageCommand
{
public:
	BlockCommand(Comportement & c);
	virtual ~BlockCommand() = default;

	virtual void execute(const std::string & param) override;
	virtual void help() const override;
};

