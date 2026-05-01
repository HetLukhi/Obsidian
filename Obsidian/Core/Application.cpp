#include "Application.h"


namespace obsidian {
	namespace core {
		Application::Application() {
			Init();
			m_Window = Window::Create({ "Obsidian Engine", 1280, 720 });
			renderer::Renderer::Init(*m_Window);
		}

		Application::~Application(){
			renderer::Renderer::Shutdown();
			m_Window.reset();
			Shutdown();
		}

		void Application::Init() {
			if(SDL_Init(SDL_INIT_VIDEO) < 0) {
				m_Running = false;
				throw std::runtime_error(std::string("Error initializing SDL: ") + SDL_GetError());
			}
		}

		void Application::Shutdown() {
			SDL_Quit();
		}

		void Application::OnEvent(renderer::Camera& camera) {
			if (event::Event::QuitRequest()) m_Running = false;
			if (event::Event::IsWindowResized()) {
				renderer::Renderer::OnWindowResize(m_Window->GetWidth(), m_Window->GetHeight());
				camera.SetViewportSize(Application::m_Window->GetWidth(), Application::m_Window->GetHeight());
			}
		}

		void Application::Run() {
			float lastFrameTime = 0.0f;

			renderer::Camera camera(Application::m_Window->GetWidth(), Application::m_Window->GetHeight());

			while (m_Running) {

				float currentTime = SDL_GetTicks() / 1000.0f;
				float deltaTime = currentTime - lastFrameTime;
				lastFrameTime = currentTime;

				event::Event::Update();
				m_Window->OnUpdate();

				OnEvent(camera);
				OnUpdate(deltaTime);

				renderer::Renderer::BeginFrame();

				OnRender();

				renderer::Renderer::EndFrame();
			}
		}
	}
}