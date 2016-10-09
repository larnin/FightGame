#include "DeathPersonnageObserver.h"

DeathPersonnageObserver::DeathPersonnageObserver(Personnage & personnage)
	: Observer<Personnage>(personnage)
{
}

void DeathPersonnageObserver::notify()
{
	if ((*m_subject)->life() == 0 && m_callBack)
		m_callBack(**m_subject);
}