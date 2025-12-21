#include "graphics.h"

namespace obsidian {
	namespace graphics {
		Window::Window() : m_Title{"Window"}, m_Width{800}, m_Height{600}, m_Window{nullptr, SDL_DestroyWindow} {
			Window_Init();
		}

		Window::Window(const std::string& title, int width, int height) : m_Title{title},m_Width{width},m_Height{height}, m_Window(nullptr, SDL_DestroyWindow) {
			Window_Init();
		}

		void Window::Window_Init() {

			this->m_Window.reset(SDL_CreateWindow(m_Title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width, m_Height, SDL_WINDOW_SHOWN));
			
			if (!m_Window) {
				throw std::runtime_error(std::string("Error creating Window: ") + SDL_GetError());
			}
		}

		int Window::GetWidth() const{
			return m_Width;
		}

		int Window::GetHeight() const{
			return m_Height;
		}

		SDL_Window* Window::Get_Native_Window() const {
			return m_Window.get();
		}

		Renderer::Renderer() : m_Renderer{nullptr,&SDL_DestroyRenderer} {}

		void Renderer::Renderer_Init(const Window& window) {
			SDL_Window* raw_window = window.Get_Native_Window();
			m_Renderer.reset(SDL_CreateRenderer(raw_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
			if (!m_Renderer) {
				throw std::runtime_error(std::string("Error creating Renderer: ") + SDL_GetError());
			}
		}

		void Renderer::BeginFrame() {
			SDL_RenderClear(m_Renderer.get());
		}

		void Renderer::EndFrame() {
			SDL_RenderPresent(m_Renderer.get());
		}
	}
}



