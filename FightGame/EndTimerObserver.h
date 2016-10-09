#pragma once

#include "Observer.h"
#include "World.h"

class EndTimerObserver : public Observer<World>
{
public:
	EndTimerObserver(World & w, unsigned int _maxTime);
	virtual ~EndTimerObserver() = default;

	virtual void notify() override;

private:
	unsigned int m_maxTime;
};

