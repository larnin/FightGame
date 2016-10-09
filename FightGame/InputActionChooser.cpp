#include "InputActionChooser.h"
#include "Comportement.h"
#include "World.h"
#include "MoveCommand.h"
#include "BlockCommand.h"
#include "AttackCommand.h"
#include "ChargeCommand.h"
#include "Utilities.h"
#include <iostream>
#include <string>

InputActionChooser::InputActionChooser(Comportement & c)
	: NextActionChooser(c)
{ 
	std::unique_ptr<PersonnageCommand> moveCMD(std::make_unique<MoveCommand>(c));
	m_commands.add(moveCMD);

	std::unique_ptr<PersonnageCommand> blockCMD(std::make_unique<BlockCommand>(c));
	m_commands.add(blockCMD);

	std::unique_ptr<PersonnageCommand> attackCMD(std::make_unique<AttackCommand>(c));
	m_commands.add(attackCMD);

	std::unique_ptr<PersonnageCommand> chargeCMD(std::make_unique<ChargeCommand>(c));
	m_commands.add(chargeCMD);
}

void InputActionChooser::update()
{
	std::cout << std::endl;
	World & w(m_comportement->personnage().world());
	w.drawWorld();
	std::cout << std::endl;
	timedWriter("Que voulez vous faire ?", 25);
	timedWriter("Utilisez 'aide' pour connaitre la liste des commandes (coute 1 tour)", 25);

	std::string commandName;
	std::getline(std::cin, commandName);
	commandName = toLower(commandName);
	m_commands.execute(commandName);
}