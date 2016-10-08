#pragma once

#include "Command.h"

class MenuState;

class MenuCommand : public Command
{
public:
	MenuCommand(MenuState & menu);
	virtual ~MenuCommand() = default;

protected:
	MenuState & m_menu;
};

class RunAdventureCommand : public MenuCommand
{
public:
	RunAdventureCommand(MenuState & menu);
	virtual ~RunAdventureCommand() = default;

	virtual void execute() override;
};

class RunSingleFightCommand : public MenuCommand
{
public:
	RunSingleFightCommand(MenuState & menu);
	virtual ~RunSingleFightCommand() = default;

	virtual void execute() override;
};

class ExitCommand : public MenuCommand
{
public:
	ExitCommand(MenuState & menu);
	virtual ~ExitCommand() = default;

	virtual void execute() override;
};