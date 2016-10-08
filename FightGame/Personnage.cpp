#include "Personnage.h"
#include "World.h"
#include <cassert>

unsigned int Personnage::lastPersonnageID(0);

Personnage::Personnage(Team _team, World & _world)
	: m_team(_team)
	, m_id(lastPersonnageID++)
	, m_world(_world)
	, m_comportement(*this)
{
}

Personnage & Personnage::operator=(Personnage && p)
{
	m_life = std::move(p.m_life);
	m_maxLife = std::move(p.m_maxLife);
	m_position = std::move(p.m_position);
	m_team = std::move(p.m_team);
	m_id = std::move(p.m_id);
	m_comportement = std::move(p.m_comportement);
	assert(&m_world == &p.m_world);//old and new Personnage are on the same world

	return *this;
}

void Personnage::update()
{

}

int Personnage::move(int value)
{
	unsigned int pos(std::min((unsigned int)(std::max(0, int(m_position) + value)), m_world.size()));
	int move(pos-m_position);
	m_position = pos;
	return move;
}

void Personnage::damage(Personnage & sender, unsigned int value)
{
    assert(sender.team() != team());

    m_life = value > m_life ? 0 : m_life - value;
    notifyObservers();
}
