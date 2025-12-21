#include "engine.h"

namespace obsidian {
	namespace core {

		Engine::Engine(){
			Init();
		}
		Engine::~Engine() {
			Shutdown();
		}

		void Engine::Init() {
			if (SDL_Init(SDL_INIT_VIDEO) < 0) {
				throw std::runtime_error(std::string("Error initializing SDL: ") + SDL_GetError());
			}
			m_Window = std::make_unique<graphics::Window>();
			m_Renderer = std::make_unique<graphics::Renderer>();
			m_Renderer->Renderer_Init(*m_Window);
		}

		void Engine::Shutdown() {
			SDL_Quit();
		}

		void Engine::Run() {
			while (m_Running) {
				
			}
		}
	}
}