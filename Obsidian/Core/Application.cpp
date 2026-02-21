#include "Application.h"


namespace obsidian {
	namespace core {
		Application::Application() {
			Init();
			m_Window = Window::Create({ "Obsidian Engine", 1280, 720 });
			obsidian::renderer::Renderer::Init(*m_Window);
		}

		Application::~Application(){
			obsidian::renderer::Renderer::Shutdown();
			m_Window.reset();
			Shutdown();
		}

		void Application::Init() {
			if(SDL_Init(SDL_INIT_VIDEO) < 0) {
				throw std::runtime_error(std::string("Error initializing SDL: ") + SDL_GetError());
				m_Running = false;
			}
		}

		void Application::Shutdown() {
			SDL_Quit();
		}

		void Application::OnEvent() {
			if (obsidian::event::Event::QuitRequest()) m_Running = false;
			if (obsidian::event::Event::IsWindowResized()) {
				obsidian::renderer::Renderer::OnWindowResize(m_Window->GetWidth(), m_Window->GetHeight());
			}
		}

		void Application::Run() {	
			while (m_Running) {
				obsidian::event::Event::Update();

				m_Window->OnUpdate();

				OnEvent();

				obsidian::renderer::Renderer::BeginFrame();
				obsidian::renderer::Renderer::EndFrame();

			}
		}
	}
}