#include "command.h"

Command::Command(std::string name, int (*callback)(int, std::string*)) :
	name{ name },
	execute{ callback }
{
	
}

int Command::run(int numArgs, std::string* args) {

	int result = execute(numArgs, args);
	return result;
}



std::list<std::string> split_str(std::string str, std::string delimiter) {
	std::list<std::string> list;

	int pos = 0;
	std::string token;
	while ((pos = str.find(delimiter)) != std::string::npos) {
		token = str.substr(0, pos);
		list.push_back(token);

		str.erase(0, pos + delimiter.length());
	}
	list.push_back(str);

	return list;
}

std::string get_command_args(std::string fullCommand, int* numArgsOut, std::string** argsOut) {
	std::list<std::string> argList = split_str(fullCommand, " ");
	std::string commandName;
	int numArgs = 0;
	std::string* args = new std::string[argList.size() - 1];

	std::list<std::string>::iterator iterator = argList.begin();
	commandName = *iterator;
	iterator++;
	while (iterator != argList.end()) {
		*(args + numArgs) = *iterator;

		numArgs++;
		iterator++;
	}

	*argsOut = args;
	*numArgsOut = numArgs;
	return commandName;
}