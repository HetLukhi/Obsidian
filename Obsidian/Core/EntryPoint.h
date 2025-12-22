#pragma once 

extern obsidian::core::Application* obsidian::core::CreateApplication();

int main(int argc, char* argv[]) {
	auto app = obsidian::core::CreateApplication();
	app->Run();
	delete app;
	return 0;
}