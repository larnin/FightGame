#pragma once

#include "Comportement.h"
#include <string>

class PersonnageCommand
{
public:
	PersonnageCommand(const std::string & _name, Comportement & c)
		: m_name(_name)
		, m_comportement(c)
	{}
	virtual ~PersonnageCommand() = default;

	virtual void execute(const std::string & param) = 0;
	virtual void help() const = 0;

	std::string name() const { return m_name; }

protected:
	std::string m_name;
	Comportement & m_comportement;
};