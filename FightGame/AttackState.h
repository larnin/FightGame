#pragma once

#include "ComportementState.h"
#include "Attack.h"
#include <vector>

class AttackState : public ComportementState
{
public:
	AttackState(Comportement & c);
	virtual ~AttackState() = default;

	virtual void update() override;

	void add(const Attack & a, unsigned int delay);

private:
	void sendAttack();

	std::vector<std::pair<unsigned int, Attack>> m_attacks;
	unsigned int m_brokenComboTime;
};

