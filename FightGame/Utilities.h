#pragma once

#include <string>
#include <random>
#include <vector>

void timedWriter(const std::string & text, unsigned int msDelay);
void clearConsole(unsigned int nbLines = 30);

std::default_random_engine& randEngine();

std::string toLower(std::string s);
std::vector<std::string> split(std::string s, char delim);
std::string combine(std::vector<std::string> str, char delim);