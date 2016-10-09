#include "CommandList.h"
#include "Utilities.h"
#include <algorithm>

void CommandList::execute(const std::string & command)
{
	auto words(split(command, ' '));
	if (words.empty())
		return;

	if (words[0] == "aide")
	{
		if (words.size() > 1)
			help(words[1]);
		else help();
		return;
	}

	const std::string & w(words[0]);
	auto it(std::_Find_if(m_commands.begin(), m_commands.end(), [w](const auto & c) {return c->name() == w; }));
	if (it == m_commands.end())
	{
		timedWriter("La commande '" + w + "' n'est pas connue !", 25);
		return;
	}
	words.erase(words.begin());
	(*it)->execute(combine(words, ' '));
}

void CommandList::help()
{
	std::string cmdList;
	for (const auto & c : m_commands)
		cmdList += c->name() + ", ";
	cmdList.pop_back();
	cmdList.pop_back();
	timedWriter("Commandes disponibles :", 25);
	timedWriter(cmdList, 25);
	timedWriter("Utilisez 'aide [commande]' pour une aide plus detaillee", 25);
}

void CommandList::help(const std::string & command)
{
	auto it(std::_Find_if(m_commands.begin(), m_commands.end(), [command](const auto & c) {return c->name() == command; }));
	if (it == m_commands.end())
	{
		timedWriter("La commande '" + command + "' n'est pas connue !", 25);
		return;
	}

	(*it)->help();
}

void CommandList::add(std::unique_ptr<PersonnageCommand> & command)
{
	m_commands.push_back(std::move(command));
}