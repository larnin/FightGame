#include "MoveCommand.h"
#include "Utilities.h"
#include "MoveState.h"
#include <exception>

MoveCommand::MoveCommand(Comportement & c)
	: PersonnageCommand("deplace", c)
{

}

void MoveCommand::execute(const std::string & param)
{
	auto words(split(param, ' '));
	if (words.size() != 2)
	{
		help();
		return;
	}

	int movedir(0);
	if (words[0] == "droite")
		movedir = 1;
	else if (words[0] == "gauche")
		movedir = -1;
	else
	{
		help();
		return;
	}

	int value(0);
	try
	{
		value = std::stoi(words[1]);
	}
	catch (const std::exception&)
	{
		help();
		return;
	}
	value *= movedir;

	std::unique_ptr<ComportementState> s(std::make_unique<MoveState>(m_comportement, value));
	m_comportement.setState(s);
}

void MoveCommand::help() const
{
	timedWriter("deplace [direction] [valeur] : Deplace le personnage.", 25);
	timedWriter("La direction peut etre 'gauche' ou 'droite'", 25);
}