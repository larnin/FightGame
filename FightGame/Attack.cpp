#include "Attack.h"

Attack::Attack(AttackType _type, bool _direction, unsigned int _knockback, Personnage & _sender, unsigned int _power, unsigned int _move)
	: m_sender(&_sender)
	, m_power(_power)
	, m_knockback(_direction ? _knockback : -(int(_knockback)))
	, m_move(_direction ? _move : -(int(_move)))
{
	createAttack(_type, _direction);
}

void Attack::createAttack(AttackType type, bool direction)
{
	unsigned int pos(m_sender->pos());
	int dir(direction ? 1 : -1);
	std::vector<int> tempTargets;

	switch (type)
	{
	case ATTACK_ZONE:
		tempTargets.push_back(pos);
		tempTargets.push_back(pos - dir);
		tempTargets.push_back(pos + dir);
		break;
	case ATTACK_NEAR:
		tempTargets.push_back(pos + dir);
		tempTargets.push_back(pos + 2 * dir);
		break;
	case ATTACK_DISTANCE:
		tempTargets.push_back(pos + 3 * dir);
		tempTargets.push_back(pos + 4 * dir);
		tempTargets.push_back(pos + 5 * dir);
		break;
	case ATTACK_CHARGE:
		tempTargets.push_back(pos);
		tempTargets.push_back(pos + dir);
		tempTargets.push_back(pos + 2 * dir);
		tempTargets.push_back(pos + 3 * dir);
		tempTargets.push_back(pos + 4 * dir);
		tempTargets.push_back(pos + 5 * dir);
	default:
		break;
	}

	for (int p : tempTargets)
		if (p > 0)
			m_targetsPos.push_back(p);
}

AttackType attackFromString(const std::string & s)
{
	if (s == "zone")
		return ATTACK_ZONE;
	if (s == "proche")
		return ATTACK_NEAR;
	if (s == "distance")
		return ATTACK_DISTANCE;
	if (s == "charge")
		return ATTACK_CHARGE;
	return ATTACK_UNKNOW;
}

std::string attackToString(AttackType a)
{
	switch (a)
	{
	case ATTACK_ZONE:
		return "zone";
	case ATTACK_NEAR:
		return "proche";
	case ATTACK_DISTANCE:
		return "distance";
	case ATTACK_CHARGE:
		return "charge";
	default: // ATTACK_UNKNOW
		return "unknow";
	}
}

unsigned int powerFromType(AttackType a)
{
	switch (a)
	{
	case ATTACK_ZONE:
		return 20;
	case ATTACK_NEAR:
		return 15;
	case ATTACK_DISTANCE:
		return 12;
	case ATTACK_CHARGE:
		return 30;
	default: // ATTACK_UNKNOW
		return 0;
	}
}