#include "Utilities.h"

#include <iostream>
#include <thread>

void timedWriter(const std::string & text, unsigned int msDelay)
{
	for (const auto & c : text)
	{
		std::cout << c;
		std::this_thread::sleep_for(std::chrono::milliseconds(msDelay));
	}
	std::cout << std::endl;
}

void clearConsole(unsigned int nbLines)
{
	while (nbLines-- > 0)
		std::cout << std::endl;
}