#include "Window.h"

namespace obsidian {
	namespace core {
		Window::Window() : m_Title{ "Window" }, m_Width{ 800 }, m_Height{ 600 }, m_Window{ nullptr, SDL_DestroyWindow } {
			Window_Init();
		}

		Window::Window(const std::string& title, int width, int height) : m_Title{ title }, m_Width{ width }, m_Height{ height }, m_Window(nullptr, SDL_DestroyWindow) {
			Window_Init();
		}

		Window::~Window(){}

		void Window::Window_Init() {

			this->m_Window.reset(SDL_CreateWindow(m_Title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width, m_Height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE));

			if (!m_Window) {
				throw std::runtime_error(std::string("Error creating Window: ") + SDL_GetError());
			}
		}

		int Window::GetWidth() const {
			return m_Width;
		}

		int Window::GetHeight() const {
			return m_Height;
		}

		void Window::OnUpdate() {
			
		}

		void Window::Resize(int width, int height) {
			m_Width = width;
			m_Height = height;
		}

		SDL_Window* Window::Get_Native_Window() const {
			return m_Window.get();
		}
	}
}