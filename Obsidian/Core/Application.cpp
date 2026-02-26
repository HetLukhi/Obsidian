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
			math::vec2 pos = { 100,100 };

			renderer::Camera camera(Application::m_Window->GetWidth(), Application::m_Window->GetHeight());

			renderer::Texture* texture = assets::AssetManager::LoadTexture(renderer::Renderer::GetNativeRenderer(), "Assets/spritesheet.png");

			components::Sprite* sprite = new components::Sprite();
			sprite->SetTexture(texture);
			sprite->SetPosition(pos);
			sprite->SetSize({ 200, 112 });

			components::Animation* animation = new components::Animation(sprite);
			for (int i = 0; i < 8; i++) {
				animation->AddFrame({ i * texture->GetWidth()/8, 0,texture->GetWidth() / 8 ,texture->GetHeight()}, 0.25f);
			}
			animation->play(true);
			float speed = 300.0f;

				while (m_Running) {

					float currentTime = SDL_GetTicks() / 1000.0f;
					float deltaTime = currentTime - lastFrameTime;
					lastFrameTime = currentTime;

					event::Event::Update();
					m_Window->OnUpdate();
					OnEvent(camera);

					if (event::Event::IsKeyHeld(SDL_SCANCODE_W)) {
						pos.y -= speed * deltaTime;
						camera.Move({ 0,-speed * deltaTime });
						sprite->SetFlip(false, true);
						sprite->SetAngle(90.0);
						sprite->SetPosition(pos);
					}
					if (event::Event::IsKeyHeld(SDL_SCANCODE_S)) {
						pos.y += speed * deltaTime;
						camera.Move({ 0,speed * deltaTime });
						sprite->SetFlip(false, true);
						sprite->SetAngle(-90.0);
						sprite->SetPosition(pos);
					}
					if (event::Event::IsKeyHeld(SDL_SCANCODE_A)) {
						pos.x -= speed * deltaTime;
						camera.Move({ -speed * deltaTime, 0 });
						sprite->SetFlip(false, false);
						sprite->SetAngle(0.0);
						sprite->SetPosition(pos);
					}
					if (event::Event::IsKeyHeld(SDL_SCANCODE_D)) {
						pos.x += speed * deltaTime;
						camera.Move({ speed * deltaTime, 0 });
						sprite->SetFlip(true, false);
						sprite->SetAngle(0.0);
						sprite->SetPosition(pos);
					}
					animation->Update(deltaTime);


					renderer::Renderer::BeginFrame();
					renderer::Renderer2D::BeginScene(camera);

					sprite->Draw(renderer::Renderer::GetNativeRenderer(), camera);
					renderer::Renderer2D::DrawQuad({ 400,400 }, { 300,100 }, { 45,45,45,255 });

					renderer::Renderer2D::EndScene();
					renderer::Renderer::EndFrame();
				}
		}
	}
}