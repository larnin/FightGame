#include "AttackCommand.h"
#include "AttackState.h"
#include "Utilities.h"
#include "Personnage.h"

AttackCommand::AttackCommand(Comportement & c)
	: PersonnageCommand("attaque", c)
{
}

void AttackCommand::execute(const std::string & param)
{
	auto words(split(param, ' '));
	std::vector<AttackType> valideTypes{ ATTACK_DISTANCE, ATTACK_NEAR, ATTACK_ZONE };
	std::vector<Attack> attacks;

	for (unsigned int i(0); i < words.size() / 2; i++)
	{
		const std::string & attackName(words[2 * i]);
		const std::string & dirName(words[2 * i + 1]);
		AttackType a(attackFromString(attackName));
		if (std::find(valideTypes.begin(), valideTypes.end(), a) == valideTypes.end())
		{
			help();
			return;
		}
		bool dir;
		if (dirName == "droite")
			dir = true;
		else if (dirName == "gauche")
			dir = false;
		else
		{
			help();
			return;
		}

		attacks.push_back(Attack(a, dir, 0, m_comportement.personnage(), powerFromType(a)));
	}

	if (attacks.empty())
	{
		help();
		return;
	}

	std::unique_ptr<AttackState> s(std::make_unique<AttackState>(m_comportement));
	for (unsigned int i(0); i < 4 && i < attacks.size(); i++)
		s->add(attacks[i], 2); 
	std::unique_ptr<ComportementState> state(std::move(s));
	m_comportement.setState(state);
}

void AttackCommand::help() const
{
	timedWriter("Attack [type] [direction] [...] : execute une attaque", 25);
	timedWriter("Il est possible de combiner jusqu'a 4 combos", 25);
	timedWriter("Une attaque prend 2 tours a s'executer", 25);
	timedWriter("Si une attaque ne touche aucun ennemi, le combot est perdu, et le joueur doit attendre 3 tours", 25);
	timedWriter("Les attaques possibles : " + attackToString(ATTACK_ZONE) + ", " + attackToString(ATTACK_NEAR) + ", " + attackToString(ATTACK_DISTANCE), 25);
	timedWriter("La direction est soit 'droite', soit 'gauche'", 25);
}

