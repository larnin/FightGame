#pragma once

#include "Observer.h"
#include "Comportement.h"
#include <memory>

enum Team
{
	PLAYER_TEAM,
	ENNEMI_TEAM
};

char charFromTeam(Team t);
std::string teamName(Team t);

class World;
class ActionChooserFactory;

class Personnage : public Subject<Personnage>
{
public:
	Personnage(const std::string & _name, unsigned int _life, Team _team, World & _world, std::unique_ptr<ActionChooserFactory> & factory);
	Personnage(const Personnage &) = delete;
	Personnage & operator=(const Personnage &) = delete;
	Personnage(Personnage && p);
	Personnage & operator=(Personnage && p);
	virtual ~Personnage() = default;

	void update();

	std::string name() const { return m_name; }
	unsigned int life() const { return m_life; }
	unsigned int maxLife() const { return m_maxLife; }
	int pos() const { return m_position; }
	Team team() const { return m_team; }
	unsigned int id() const { return m_id; }
	World & world() { return m_world; }

    int move(int value); //retourne le deplacement reel

	void damage(Personnage & sender, unsigned int value);

private:
	std::string m_name;
	unsigned int m_life;
	unsigned int m_maxLife;
	int m_position;
	Team m_team;
	unsigned int m_id;
	World & m_world;
	Comportement m_comportement;

	static unsigned int lastPersonnageID;
};

