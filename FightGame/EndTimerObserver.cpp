#include "EndTimerObserver.h"



EndTimerObserver::EndTimerObserver(World & w, unsigned int _maxTime)
	: Observer<World>(w)
	, m_maxTime(_maxTime)
{

}

void EndTimerObserver::notify()
{
	if ((*m_subject)->time() >= m_maxTime && m_callBack)
		m_callBack(**m_subject);
}