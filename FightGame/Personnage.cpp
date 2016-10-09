#include "Personnage.h"
#include "World.h"
#include "BlockState.h"
#include "Utilities.h"
#include <cassert>

unsigned int Personnage::lastPersonnageID(0);

char charFromTeam(Team t)
{
	switch (t)
	{
	case PLAYER_TEAM:
		return 'O';
	case ENNEMI_TEAM:
		return 'X';
	default:
		return '#';
	}
}

std::string teamName(Team t)
{
	switch (t)
	{
	case PLAYER_TEAM:
		return "Joueur";
	case ENNEMI_TEAM:
		return "Ennemi";
	default:
		return "Unknow";
	}
}

Personnage::Personnage(const std::string & _name, unsigned int _life, Team _team, World & _world, std::unique_ptr<ActionChooserFactory> & factory)
	: m_name(_name)
	, m_life(_life)
	, m_maxLife(_life)
	, m_team(_team)
	, m_id(lastPersonnageID++)
	, m_world(_world)
	, m_comportement(*this, factory)
{

}

Personnage::Personnage(Personnage && p)
	: m_name(p.m_name)
	, m_life(std::move(p.m_life))
	, m_maxLife(std::move(p.m_maxLife))
	, m_position(std::move(p.m_position))
	, m_team(std::move(p.m_team))
	, m_id(std::move(p.m_id))
	, m_comportement(std::move(p.m_comportement))
	, m_world(std::move(p.m_world))
{
	m_comportement.m_personnage = this;
}

Personnage & Personnage::operator=(Personnage && p)
{
	m_name = std::move(p.m_name);
	m_life = std::move(p.m_life);
	m_maxLife = std::move(p.m_maxLife);
	m_position = std::move(p.m_position);
	m_team = std::move(p.m_team);
	m_id = std::move(p.m_id);
	m_comportement = std::move(p.m_comportement);
	assert(&m_world == &p.m_world);//old and new Personnage are on the same world

	m_comportement.m_personnage = this;

	return *this;
}

void Personnage::update()
{
	m_comportement.update();
}

int Personnage::move(int value)
{
	unsigned int pos(std::min((unsigned int)(std::max(0, int(m_position) + value)), m_world.size()-1));
	int move(pos-m_position);
	m_position = pos;
	return move;
}

void Personnage::damage(Personnage & sender, unsigned int value)
{
    assert(sender.team() != team());

	if (typeid(m_comportement.current()) == typeid(BlockState))
		value /= 3;

    m_life = value > m_life ? 0 : m_life - value;
    notifyObservers();

	timedWriter(name() + " prend " + std::to_string(value) + " degas par l'attaque de " + sender.name(), 25);
}
