#include "MenuCommand.h"
#include "MenuState.h"

MenuCommand::MenuCommand(MenuState & menu)
	: m_menu(menu)
{

}

RunAdventureCommand::RunAdventureCommand(MenuState & menu)
	: MenuCommand(menu)
{

}

void RunAdventureCommand::execute()
{
	m_menu.runAdventure();
}

RunSingleFightCommand::RunSingleFightCommand(MenuState & menu)
	: MenuCommand(menu)
{

}

void RunSingleFightCommand::execute()
{
	m_menu.runSingleFight();
}

ExitCommand::ExitCommand(MenuState & menu)
	: MenuCommand(menu)
{

}

void ExitCommand::execute()
{
	m_menu.exit();
}