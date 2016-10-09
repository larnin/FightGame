#include "Utilities.h"

#include <iostream>
#include <thread>
#include <algorithm>
#include <cctype>

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

std::default_random_engine& randEngine()
{
	static std::default_random_engine e;
	return e;
}

std::string toLower(std::string s)
{
	for (auto & c : s)
		c = std::tolower(c);
	return s;
}

std::vector<std::string> split(std::string s, char delim)
{
	std::vector<std::string> str;
	while (!s.empty())
	{
		auto index(s.find_first_of(delim));
		if (index == std::string::npos)
		{
			str.push_back(s);
			break;
		}
		std::string elem(s.substr(0, index));
		s = s.substr(index + 1);
		if (!elem.empty())
			str.push_back(elem);
	}
	return str;
}

std::string combine(std::vector<std::string> str, char delim)
{
	std::string s;

	for (const auto & v : str)
	{
		s += v;
		s += delim;
	}
	if(!s.empty())
		s.pop_back();
	return s;
}