#include "World.h"
#include <algorithm>
#include <cassert>

World::World(unsigned int size)
	: m_size(size)
{

}

void World::update()
{

}

void World::addPersonnage(Personnage & p)
{
	assert(std::find_if(m_personnages.begin(), m_personnages.end(), [&p](const auto & pl) {return p.id() == pl.id(); }) != m_personnages.end());
	assert(&p.world() == this);
	p.move(0); //to replace personnage on the current arena
	
	m_personnages.push_back(std::move(p));
}

void World::delPersonnage(unsigned int id)
{
	if (m_personnages.empty())
		return;

	auto it(std::find_if(m_personnages.begin(), m_personnages.end(), [id](const auto & pl) {return id == pl.id(); }));
	std::swap(*it, m_personnages.back());
	m_personnages.pop_back();
}

std::vector<unsigned int> World::personnages() const
{
	std::vector<unsigned int> ids;
	for (const auto & p : m_personnages)
		ids.push_back(p.id());
	return ids;
}

const Personnage & World::personnage(unsigned int id) const
{
	auto it(std::_Find_if(m_personnages.begin(), m_personnages.end(), [id](const auto & p) { return p.id() == id; }));
	assert(it != m_personnages.end());
	return *it;
}