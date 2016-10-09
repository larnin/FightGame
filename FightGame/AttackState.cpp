#include "AttackState.h"
#include "Comportement.h"
#include "Utilities.h"
#include "Personnage.h"
#include "World.h"

AttackState::AttackState(Comportement & c)
	: ComportementState(c)
	, m_brokenComboTime(0)
{
}

void AttackState::update()
{
	if (m_attacks.empty())
	{
		if (m_brokenComboTime != 0)
		{
			m_brokenComboTime--;
			return;
		}
		m_comportement->setDefaultState();
		return;
	}
	m_attacks.front().first--;
	if (m_attacks.front().first == 0)
		sendAttack();
}

void AttackState::add(const Attack & a, unsigned int delay)
{
	if (delay == 0)
		delay = 1;
	m_attacks.emplace_back(delay, a);
}

void AttackState::sendAttack()
{
	World & w(m_comportement->personnage().world());
	if (!w.attack(m_attacks.front().second))
	{
		m_attacks.clear();
		m_brokenComboTime = 3;
		timedWriter(m_comportement->personnage().name() + " rate son attaque !", 25);
		return;
	}
	m_attacks.erase(m_attacks.begin());
}