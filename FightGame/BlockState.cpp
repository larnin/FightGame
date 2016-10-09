#include "BlockState.h"
#include "Comportement.h"
#include "Utilities.h"
#include "Personnage.h"

BlockState::BlockState(Comportement & c, unsigned int time)
	: ComportementState(c)
	, m_time(time)
{

}


void BlockState::update()
{
	if (m_time == 0)
	{
		m_comportement->setDefaultState();
		return;
	}

	m_time--;
	timedWriter(m_comportement->personnage().name() + " bloque.", 25);

	if (m_time == 0)
	{
		m_comportement->setDefaultState();
		return;
	}
}
