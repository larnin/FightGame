#pragma once

#include "State.h"
#include "World.h"
#include "DeathPersonnageObserver.h"
#include "EndTimerObserver.h"
#include <memory>

class SingleFightState : public State
{
public:
	SingleFightState(Game & game);
	virtual ~SingleFightState() = default;

	virtual void update() override;

private:
	void onPersonnageDie(Personnage &);
	void onTimerEnd(World &);
	void returnToMenu();

	World m_world;
	std::unique_ptr<DeathPersonnageObserver> m_playerObserver;
	std::unique_ptr<DeathPersonnageObserver> m_ennemiObserver;
	std::unique_ptr<EndTimerObserver> m_timerObserver;
};

