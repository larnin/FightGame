#pragma once

#include <memory>
#include "ComportementState.h"
#include "ActionChooserFactory.h"

class Personnage;

class Comportement
{
	friend Personnage;
public:
	Comportement(Personnage & p, std::unique_ptr<ActionChooserFactory> & factory);
	Comportement(const Comportement &) = delete;
	Comportement & operator=(const Comportement &) = delete;
	Comportement(Comportement && c);
	Comportement & operator=(Comportement && c);
    ~Comportement() = default;

	void update();
	void setState(std::unique_ptr<ComportementState> & state);
	void setDefaultState();
	const ComportementState & current() const;
	Personnage & personnage();

private:
	Personnage * m_personnage;
	std::unique_ptr<ComportementState> m_current;
	std::unique_ptr<ActionChooserFactory> m_factory;
};

