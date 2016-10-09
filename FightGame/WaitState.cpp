#include "WaitState.h"
#include "Comportement.h"
#include "Personnage.h"
#include "Utilities.h"

WaitState::WaitState(Comportement & c, unsigned int time)
	: ComportementState(c)
	, m_time(time)
	, m_messageFired(false)
{
	if (m_time < 1)
		m_time++;
}

void WaitState::update()
{
	if (!m_messageFired)
	{
		Personnage & p(m_comportement->personnage());
		timedWriter(p.name() + " attend " + std::to_string(m_time) + " tours.", 25);
		m_messageFired = true;
	}
	m_time--;
	if (m_time == 0)
		m_comportement->setDefaultState();
}
