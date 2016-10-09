#pragma once

#include "Personnage.h"
#include <vector>

enum AttackType
{
	ATTACK_ZONE,
	ATTACK_NEAR,
	ATTACK_DISTANCE,
	ATTACK_CHARGE,
	ATTACK_UNKNOW
};

AttackType attackFromString(const std::string & s);
std::string attackToString(AttackType a);
unsigned int powerFromType(AttackType a);

class Attack
{
public:
	Attack(AttackType _type, bool _direction, unsigned int _knockback, Personnage & _sender, unsigned int _power, unsigned int _move = 0);

	Personnage & sender() const { return *m_sender; }
	std::vector<unsigned int> targets() const { return m_targetsPos; }
	unsigned int power() const { return m_power; }
	int knockback() const { return m_knockback; }
	int move() const { return m_move; }

private:
	void createAttack(AttackType type, bool direction);
	Personnage * m_sender;
	std::vector<unsigned int> m_targetsPos;
	unsigned int m_power;
	int m_knockback;
	int m_move;
};

