#include "Application.h"


namespace obsidian {
	namespace core {
		Application::Application() {
			Init();
			m_Window = Window::Create({ "Obsidian Engine", 1280, 720 });
			renderer::Renderer::Init(*m_Window);
			renderer::Renderer2D::Init();
			renderer::Texture::Init();
		}

		Application::~Application(){
			renderer::Texture::Shutdown();
			renderer::Renderer2D::Shutdown();
			renderer::Renderer::Shutdown();
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

					renderer::Renderer::BeginFrame();
					renderer::Renderer2D::BeginScene(camera);
					
					renderer::Renderer2D::EndScene();
					renderer::Renderer::EndFrame();
				}
		}
	}
}