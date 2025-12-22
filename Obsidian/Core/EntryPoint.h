#pragma once 
#include <iostream>

extern obsidian::core::Application* obsidian::core::CreateApplication();

int main(int argc, char* argv[]) {
	int exit_code = EXIT_SUCCESS;
	try {
		auto app = obsidian::core::CreateApplication();
		app->Run();
	}
	catch (std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		exit_code = EXIT_FAILURE;
	}
	return exit_code;
}