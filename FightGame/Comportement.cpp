#include "Comportement.h"
#include "Personnage.h"
#include <cassert>

Comportement::Comportement(Personnage & p, std::unique_ptr<ActionChooserFactory> & factory)
	: m_personnage(&p)
	, m_factory(std::move(factory))
{

}

Comportement::Comportement(Comportement && c)
	: m_personnage(std::move(c.m_personnage))
	, m_current(std::move(c.m_current))
	, m_factory(std::move(c.m_factory))
{
	if(m_current)
		m_current->m_comportement = this;
}

Comportement & Comportement::operator=(Comportement && c)
{
	m_personnage = std::move(c.m_personnage);
	m_current = std::move(m_current);
	m_factory = std::move(m_factory);

	if(m_current)
		m_current->m_comportement = this;

	return *this;
}

void Comportement::update()
{
	if (!m_current)
		setDefaultState();
	m_current->update();
}

const ComportementState & Comportement::current() const
{
	assert(m_current);
	return *m_current;
}

void Comportement::setState(std::unique_ptr<ComportementState> & state)
{
	assert(state);
	m_current = std::move(state);
}

void Comportement::setDefaultState()
{
	m_current = m_factory->createAction(*this);
}

Personnage & Comportement::personnage()
{
	return *m_personnage;
}