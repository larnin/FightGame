#pragma once

#include "Personnage.h"
#include "Attack.h"
#include "Observer.h"
#include <vector>

class World : public Subject<World>
{
public:
	World(unsigned int size);

	void update();
	void addPersonnage(Personnage & p);
	void delPersonnage(unsigned int id);
	std::vector<unsigned int> personnages() const;
	bool personnageExist(unsigned int id) const;
	const Personnage & personnage(unsigned int id) const;
	const Personnage & personnageAt(unsigned int pos) const;
	bool havePersonnageAt(unsigned int pos) const;

	unsigned int size() const { return m_size; }
	unsigned int time() const { return m_time; }
	void drawWorld() const;

	bool attack(const Attack & a);

private:
	unsigned int m_size;
	std::vector<Personnage> m_personnages;
	unsigned int m_time;
};

