#pragma once

#include "Observer.h"
#include "Comportement.h"

enum Team
{
	PLAYER_TEAM,
	ENNEMI_TEAM
};

class World;

class Personnage : public Subject<Personnage>
{
public:
	Personnage(Team _team, World & _world);
	Personnage(const Personnage &) = delete;
	Personnage & operator=(const Personnage &) = delete;
	Personnage(Personnage &&) = default;
	Personnage & operator=(Personnage && p);
	virtual ~Personnage() = default;

	void update();

	unsigned int life() const { return m_life; }
	unsigned int maxLife() const { return m_maxLife; }
	int pos() const { return m_position; }
	Team team() const { return m_team; }
	unsigned int id() const { return m_id; }
	World & world() const { return m_world; }

    int move(int value); //retourne le deplacement reel

	void damage(Personnage & sender, unsigned int value);

private:
	unsigned int m_life;
	unsigned int m_maxLife;
	int m_position;
	Team m_team;
	unsigned int m_id;
	World & m_world;
	Comportement m_comportement;

	static unsigned int lastPersonnageID;
};

