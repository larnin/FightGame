#pragma once

#include <memory>

class Personnage;
class ComportementState;

class Comportement
{
public:
	Comportement(Personnage & p);
	Comportement(const Comportement &) = delete;
	Comportement & operator=(const Comportement &) = delete;
	Comportement(Comportement &&) = default;
	Comportement & operator=(Comportement && c);

	void update();
	//void setState(std::unique_ptr<ComportementState> & state);
	//const ComportementState & current() const;

private:
	Personnage & m_personnage;
	std::unique_ptr<ComportementState> m_current;
};

