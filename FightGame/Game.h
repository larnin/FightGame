#pragma once

#include <memory>

class State;

class Game
{
public:
	void run();
	void setState(std::unique_ptr<State> & state);

private:
	std::unique_ptr<State> m_current;
};

