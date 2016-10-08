#pragma once

#include "Personnage.h"
#include <vector>

class World
{
public:
	World(unsigned int size);

	void update();
	void addPersonnage(Personnage & p);
	void delPersonnage(unsigned int id);
	std::vector<unsigned int> personnages() const;
	const Personnage & personnage(unsigned int id) const;

	unsigned int size() const { return m_size; }

private:
	unsigned int m_size;
	std::vector<Personnage> m_personnages;
};

