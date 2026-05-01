#include "Obsidian.h"

using namespace obsidian;

class Sandbox : public obsidian::core::Application {
private:
    // Game Variables

public:
    Sandbox() {
        renderer::Renderer2D::Init();
        renderer::Texture::Init();
        Init();
    }

    ~Sandbox() {
        renderer::Texture::Shutdown();
        renderer::Renderer2D::Shutdown();
    }

    void Init() {
        // Setup world and objects
    }

    void OnUpdate(float deltaTime) override {
        // Update logic
    }

    void OnRender() override {
        // Render calls
    }
};

obsidian::core::Application* obsidian::core::CreateApplication() {
    return new Sandbox();
}
