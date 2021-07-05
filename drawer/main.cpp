#include <iostream>
#include <string>
#include <assert.h>

#include "command.h"
#include "Vector2i.h"
#include "winUtil.h"
#include "GarticGame.h"

GarticGame game;

Command commands[] = {
	Command(
		"exit",

		[](int numArgs, std::string* args) -> int {
			return -1;
		}
	),

	Command(
		"setbounds",

		[](int numArgs, std::string* args) -> int {
			game.setTopLeft(Vector2i(2323, 201));
			game.setBottomRight(Vector2i(3490, 953));

			return 0;
		}
	),

	Command(
		"image",

		[](int numArgs, std::string* args) -> int {
			assert(numArgs > 0);

			std::string imagename = *(args + 0);
			game.drawImage(imagename);

			return 0;
		}
	),

	Command(
		"clear",

		[](int numArgs, std::string* args) -> int {
			game.clear();

			return 0;
		}
	),

	Command(
		"tl",

		[](int numArgs, std::string* args) -> int {
			Vector2i mousePos = getMousePos();
			game.setTopLeft(mousePos);
			return 0;
		}
	),

	Command(
		"br",

		[](int numArgs, std::string* args) -> int {
			Vector2i mousePos = getMousePos();
			game.setBottomRight(mousePos);
			return 0;
		}
	),
};

int NUM_COMMANDS = sizeof(commands) / sizeof(commands[0]);
int process_command(std::string fullCommand) {
	std::string* argsOut;
	int numArgs;

	std::string commandName = get_command_args(fullCommand, &numArgs, &argsOut);

	for (int i = 0; i < NUM_COMMANDS; i++) {
		Command command = commands[i];

		if (command.name == commandName) {
			int res = command.run(numArgs, argsOut);
			printf("\n");
			return res;
		}
	}

	printf("command not recognized\n");
}

int main()
{
	for (std::string line; std::getline(std::cin, line);) {
		if (process_command(line) < 0) {
			break;
		}
	}

	return 0;
}

