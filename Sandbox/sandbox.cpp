#include "Obsidian.h"

class Sandbox : public obsidian::core::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}

};
obsidian::core::Application* obsidian::core::CreateApplication() {
	return new Sandbox();
}