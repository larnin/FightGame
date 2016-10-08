#pragma once

#include "Observer.h"
#include "Personnage.h"

class DeathPersonnageObserver : public Observer<Personnage>
{
public:
	DeathPersonnageObserver(Personnage & personnage);
	virtual ~DeathPersonnageObserver() = default;

	virtual void notify() override;
};

