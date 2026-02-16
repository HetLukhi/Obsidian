#include "Application.h"


namespace obsidian {
	namespace core {
		Application::Application() {
			Init();
			m_Window = Window::Create({ "Obsidian Engine", 1280, 720 });
			m_Renderer = std::make_unique<obsidian::renderer::Renderer>();
			m_Renderer->Renderer_Init(*m_Window);
		}
		Application::~Application(){
			m_Renderer.reset();
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
		void Application::Run() {	
			while (m_Running) {
				obsidian::event::Event::PollEvent();
				obsidian::event::Event::Update();

				if (obsidian::event::Event::QuitRequest() == true) m_Running = false;

				m_Window->OnUpdate();
				
				m_Renderer->BeginFrame();
				m_Renderer->EndFrame();

			}
		}
	}
}