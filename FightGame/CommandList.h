#pragma once

#include "PersonnageCommand.h"
#include <string>
#include <vector>
#include <memory>

class CommandList
{
public:
	CommandList() = default;
	void execute(const std::string & command);

	void add(std::unique_ptr<PersonnageCommand> & command);

private:
	void help();
	void help(const std::string & command);

	std::vector<std::unique_ptr<PersonnageCommand>> m_commands;
};

