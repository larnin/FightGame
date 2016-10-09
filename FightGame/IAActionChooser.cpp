#include "IAActionChooser.h"
#include "Utilities.h"
#include "Comportement.h"
#include "AttackState.h"
#include "BlockState.h"
#include "MoveState.h"
#include "WaitState.h"
#include <vector>

std::unique_ptr<ComportementState> createAttack(Comportement & c)
{
	unsigned int attackCount(std::uniform_int_distribution<unsigned int>(1, 4)(randEngine()));
	auto s(std::make_unique<AttackState>(c));
	std::vector<AttackType> validTypes{ATTACK_DISTANCE, ATTACK_NEAR, ATTACK_ZONE};

	for (unsigned int i(0); i < attackCount; i++)
	{
		AttackType a(validTypes[std::uniform_int_distribution<unsigned int>(0, validTypes.size() - 1)(randEngine())]);
		bool dir(std::uniform_int_distribution<unsigned int>(0, 1)(randEngine()) == 0);
		s->add(Attack(a, dir, 0, c.personnage(), powerFromType(a), 0), 2);
	}
	return std::move(s);
}

std::unique_ptr<ComportementState> createBlock(Comportement & c)
{
	unsigned int blockTime(std::uniform_int_distribution<unsigned int>(1, 6)(randEngine()));
	return std::make_unique <BlockState>(c, blockTime);
}

std::unique_ptr<ComportementState> createMove(Comportement & c)
{
	int dir(std::uniform_int_distribution<int>(-5, 5)(randEngine()));
	return std::make_unique<MoveState>(c, dir);
}

std::unique_ptr<ComportementState> createWait(Comportement & c)
{
	unsigned int waitTime(std::uniform_int_distribution<unsigned int>(1, 5)(randEngine()));
	return std::make_unique<WaitState>(c, waitTime);
}

std::unique_ptr<ComportementState> createCharge(Comportement & c)
{
	bool dir(std::uniform_int_distribution<unsigned int>(0, 1)(randEngine()) == 0);
	auto s(std::make_unique<AttackState>(c));
	s->add(Attack(ATTACK_CHARGE, dir, 2, c.personnage(), powerFromType(ATTACK_CHARGE), 3), 4);
	return std::move(s);
}

std::unique_ptr<ComportementState> createState(StateType type, Comportement & c)
{
	switch (type)
	{
	case ATTACK_STATE:
		return createAttack(c);
	case BLOCK_STATE:
		return createBlock(c);
	case MOVE_STATE:
		return createMove(c);
	case WAIT_STATE:
		return createWait(c);
	default: //CHARGE_STATE
		return createCharge(c);
	}
}

void IAActionChooser::update()
{
	std::vector<unsigned int> poids{ 10, 20, 20, 5, 5 };
	std::vector<StateType> states{ ATTACK_STATE, BLOCK_STATE, MOVE_STATE, WAIT_STATE, CHARGE_STATE };
	unsigned int index(std::discrete_distribution<unsigned int>(poids.begin(), poids.end())(randEngine()));

	m_comportement->setState(createState(states[index], *m_comportement));
}