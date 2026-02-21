#include "Application.h"


namespace obsidian {
	namespace core {
		Application::Application() {
			Init();
			m_Window = Window::Create({ "Obsidian Engine", 1280, 720 });
			obsidian::renderer::Renderer::Init(*m_Window);
			obsidian::renderer::Renderer2D::Init();
		}

		Application::~Application(){
			obsidian::renderer::Renderer2D::Shutdown();
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

			obsidian::renderer::Camera camera(1280.0f,720.0f);
			camera.SetPosition({ 0.0f, 0.0f });
			float lastFrameTime = 0.0f;
			math::vec2 recPos = { 300,200 };

			while (m_Running) {

				float currentTime = SDL_GetTicks() / 1000.0f;
				float deltatime = currentTime - lastFrameTime;
				lastFrameTime = currentTime;

				obsidian::event::Event::Update();

				m_Window->OnUpdate();

				OnEvent();

				obsidian::renderer::Renderer::BeginFrame();
				obsidian::renderer::Renderer2D::DrawQuad(recPos, { 100,50 }, obsidian::renderer::Color(255, 255, 255, 255));
				obsidian::renderer::Renderer::EndFrame();

			}
		}
	}
}