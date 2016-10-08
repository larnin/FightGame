#include "DeathPersonnageObserver.h"

DeathPersonnageObserver::DeathPersonnageObserver(Personnage & personnage)
	: Observer<Personnage>(personnage)
{
}

void DeathPersonnageObserver::notify()
{

}