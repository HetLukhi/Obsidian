#include "Application.h"


namespace obsidian {
	namespace core {
		Application::Application() {
			Init();
			m_Window = std::make_unique<obsidian::core::Window>("Obsidian",800,600);
			m_Renderer = std::make_unique<obsidian::renderer::Renderer>();
			m_Renderer->Renderer_Init(*m_Window);
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

				obsidian::event::Event::Update();

				SDL_Event event;
				while (SDL_PollEvent(&event)) {
					obsidian::event::Event::ProcessEvent(event);
				}

				if (obsidian::event::Event::QuitRequest()) {
					m_Running = false;
				}

				if (obsidian::event::Event::IsWindowResized()) {
					int width, height;
					obsidian::event::Event::GetWindowSize(width, height);

					m_Window->Resize(width, height);
				}

				m_Renderer->BeginFrame();
				m_Renderer->EndFrame();
			}
		}
	}
}