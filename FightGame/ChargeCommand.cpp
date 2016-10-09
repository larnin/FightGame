#include "ChargeCommand.h"
#include "AttackState.h"
#include "Utilities.h"

ChargeCommand::ChargeCommand(Comportement & c)
	: PersonnageCommand("charge", c)
{

}

void ChargeCommand::execute(const std::string & param)
{
	auto words(split(param, ' '));
	if (words.empty())
	{
		help();
		return;
	}

	bool dir;
	if (words[0] == "droite")
		dir = true;
	else if (words[0] == "gauche")
		dir = false;
	else
	{
		help();
		return;
	}

	std::unique_ptr<AttackState> s(std::make_unique<AttackState>(m_comportement));
	s->add(Attack(ATTACK_CHARGE, dir, 2, m_comportement.personnage(), powerFromType(ATTACK_CHARGE), 3), 4);
	std::unique_ptr<ComportementState> state(std::move(s));
	m_comportement.setState(state);
}

void ChargeCommand::help() const
{
	timedWriter("charge [direction] : Execute une attaque chargee", 25);
	timedWriter("L'attaque prend 4 tours a etre executee", 25);
	timedWriter("Le joueur se deplace de 3 cases, et execute une attaque de 5 cases", 25);
	timedWriter("Les personnages touche reculent de 2 cases", 25);
}