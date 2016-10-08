#include "Comportement.h"
#include "Personnage.h"
#include "ComportementState.h"
#include <cassert>

Comportement::Comportement(Personnage & p)
	: m_personnage(p)
{
}

Comportement & Comportement::operator=(Comportement && c)
{
	assert(&m_personnage == &(c.m_personnage));

	m_current = std::move(m_current);
	return *this;
}

void Comportement::update()
{
	//assert(m_current);
	//m_current->update();
}

/*const ComportementState & Comportement::current() const
{
	assert(m_current);
	return *m_current;
}

void Comportement::setState(std::unique_ptr<ComportementState> & state)
{
	m_current = std::move(state);
}*/