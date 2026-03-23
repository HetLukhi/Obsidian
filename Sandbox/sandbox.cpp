#include "Obsidian.h"

class Sandbox : public obsidian::core::Application {
public:
	Sandbox() {
		
	}

	~Sandbox() {

	}

	void OnUpdate(float deltaTime) override {

	}
	
	void OnRender() override {

	}

};

obsidian::core::Application* obsidian::core::CreateApplication() {
	return new Sandbox();
}