#include "MoveState.h"
#include "Comportement.h"
#include "Personnage.h"
#include "Utilities.h"
#include <iostream>
#include <string>

MoveState::MoveState(Comportement & c, int dir)
	: ComportementState(c)
	, m_move(dir)
{

}


void MoveState::update()
{
	if (abs(m_move) == 0)
	{
		m_comportement->setDefaultState();
		return;
	}

	Personnage & p(m_comportement->personnage());
	int singleMove(m_move / abs(m_move));
	int value(p.move(singleMove));
	if (value == 0)
	{
		timedWriter(p.name() + " touche le mur de l'arene ", 25);
		m_move = 0;
		return;
	}
	timedWriter(p.name() + " se deplace vers " + std::to_string(p.pos()), 25);

	m_move -= value;

	if (abs(m_move) == 0)
	{
		m_comportement->setDefaultState();
		return;
	}
}