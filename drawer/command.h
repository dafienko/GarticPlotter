#pragma once

#include <string>
#include <list>
#include <iterator>
#include <iostream>

class Command {
private:
	int (*execute)(int, std::string*);

public:

	const std::string name;
	Command(std::string name, int (*callback)(int, std::string*));

	int run(int numArgs, std::string* args);
};

std::list<std::string> split_str(std::string str, std::string delimiter);
std::string get_command_args(std::string fullCommand, int* numArgsOut, std::string** argsOut);