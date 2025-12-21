#include "engine.h"
#include <iostream>

int main(int argc, char* argv[]) {
	int exit_code = EXIT_SUCCESS;
	try {
		obsidian::core::Engine engine;
		engine.Run();
	}
	catch (std::runtime_error &e) {
		std::cerr << e.what() << std::endl;
		exit_code = EXIT_FAILURE;
	}
	return exit_code;
}