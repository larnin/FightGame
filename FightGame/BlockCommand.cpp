#include "BlockCommand.h"
#include "Utilities.h"
#include "BlockState.h"
#include <exception>
#include <string>

BlockCommand::BlockCommand(Comportement & c)
	: PersonnageCommand("bloque", c)
{
}

void BlockCommand::execute(const std::string & param)
{
	auto words(split(param, ' '));

	int blockTime(3);
	if (!words.empty())
	{
		try
		{
			blockTime = stoi(words[0]);
		}
		catch (const std::exception&)
		{
			timedWriter("Le temps entre est invalide, 3 est utilisé !", 25);
			blockTime = 3;
		}
		if (blockTime < 0)
			blockTime = 3;
	}

	std::unique_ptr<ComportementState> s(std::make_unique<BlockState>(m_comportement, blockTime));
	m_comportement.setState(s);
}

void BlockCommand::help() const
{
	timedWriter("bloque : bloque pendant 3 tours", 25);
	timedWriter("bloque [temps] : Bloque pendant un certain temps", 25);
	timedWriter("Les degas recus pendant le bloque est divisé par 3", 25);
}