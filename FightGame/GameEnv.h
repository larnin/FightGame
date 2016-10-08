#pragma once
class GameEnv
{
public:
	GameEnv();

	void update();

	static GameEnv & instance()
	{
		static GameEnv env;
		return env;
	}
};

