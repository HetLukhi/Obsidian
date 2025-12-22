#include "Application.h"

namespace obsidian {
	namespace core {
		Application::Application() {
			Init();
			m_Window = std::make_unique<obsidian::core::Window>("Obsidian",800,600);
		}
		Application::~Application(){
			m_Window.reset();
			Shutdown();
		}
		void Application::Init() {
			if(SDL_Init(SDL_INIT_VIDEO) < 0) {
				throw std::runtime_error(std::string("Error initializing SDL: ") + SDL_GetError());
			}
		}
		void Application::Shutdown() {
			SDL_Quit();
		}
		void Application::Run() {	
			while (m_Running) {

			}
		}
	}
}