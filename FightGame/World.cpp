#include "World.h"
#include <algorithm>
#include <cassert>
#include <string>
#include <iostream>

World::World(unsigned int size)
	: m_size(size)
	, m_time(0)
{

}

void World::update()
{
	for (Personnage & p : m_personnages)
		p.update();
	m_time++;
}

void World::addPersonnage(Personnage & p)
{
	assert(std::find_if(m_personnages.begin(), m_personnages.end(), [&p](const auto & pl) {return p.id() == pl.id(); }) == m_personnages.end());
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

bool World::personnageExist(unsigned int id) const
{
	return std::find_if(m_personnages.begin(), m_personnages.end(), [id](const auto & p) { return p.id() == id; }) != m_personnages.end();
}

const Personnage & World::personnage(unsigned int id) const
{
    auto it(std::find_if(m_personnages.begin(), m_personnages.end(), [id](const auto & p) { return p.id() == id; }));
	assert(it != m_personnages.end());
	return *it;
}

const Personnage & World::personnageAt(unsigned int pos) const
{
	auto it(std::find_if(m_personnages.begin(), m_personnages.end(), [pos](const auto & p) { return p.pos() == pos; }));
	assert(it != m_personnages.end());
	return *it;
}

bool World::havePersonnageAt(unsigned int pos) const
{
	return std::find_if(m_personnages.begin(), m_personnages.end(), [pos](const auto & p) { return p.pos() == pos; }) != m_personnages.end();
}

void World::drawWorld() const
{
	std::cout << std::endl;
	std::cout << "Temps : " << m_time << std::endl << "|";

	for (unsigned int i(0); i < size(); i++)
	{
		if (havePersonnageAt(i))
			std::cout << charFromTeam(personnageAt(i).team());
		else std::cout << "_";
		if (i < size() - 1)
			std::cout << " ";
	}
	std::cout << "|" << std::endl;
	std::cout << "Vous : " << charFromTeam(PLAYER_TEAM) << " - Ennemi : " << charFromTeam(ENNEMI_TEAM) << std::endl << std::endl;

	for (const auto & p : m_personnages)
		std::cout << p.name() << " - Vie : " << p.life() << "/" << p.maxLife() << " - " << teamName(p.team()) << std::endl;
}

bool World::attack(const Attack & a)
{
	bool touched(false);
	Team t(a.sender().team());
	for (Personnage & p : m_personnages)
	{
		if (p.team() == t)
			continue;
		for (unsigned int pos : a.targets())
		{
			if (p.pos() == pos)
			{
				p.damage(a.sender(), a.power());
				p.move(a.knockback());
				touched = true;
				break;
			}
		}
	}
	if (a.move() != 0)
		a.sender().move(a.move());
	return touched;
}