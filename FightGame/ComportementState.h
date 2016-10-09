#pragma once

class Comportement;

class ComportementState
{
	friend Comportement;

public:
	ComportementState(Comportement & c)
		: m_comportement(&c)
	{ }

	ComportementState(const ComportementState &) = delete;
	ComportementState & operator=(const ComportementState &) = delete;
	virtual ~ComportementState() = default;

	virtual void update() = 0;

protected:
	Comportement * m_comportement;
};
