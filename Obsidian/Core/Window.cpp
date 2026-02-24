#include "Window.h"

namespace obsidian {
	namespace core {
		Window::Window(const WindowProps& props) : m_Window(nullptr, SDL_DestroyWindow) {
			Init(props);
		}

		std::unique_ptr<Window> Window::Create(const WindowProps& props) {
			return std::make_unique<Window>(props);
		}

		void Window::Init(const WindowProps& props) {
			m_Data.Title = props.Title;
			m_Data.Width = props.Width;
			m_Data.Height = props.Height;
			this->m_Window.reset(SDL_CreateWindow(m_Data.Title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Data.Width, m_Data.Height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE));

			if (!m_Window) {
				throw std::runtime_error(std::string("Error creating Window: ") + SDL_GetError());
			}
		}

		unsigned int Window::GetWidth() const {
			return m_Data.Width;
		}

		unsigned int Window::GetHeight() const {
			return m_Data.Height;
		}

		void Window::OnUpdate() {
			
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				event::Event::ProcessEvent(event);
			}

			if (event::Event::IsWindowResized())
			{
				int w, h;
				event::Event::GetWindowSize(w, h);
				m_Data.Width = w;
				m_Data.Height = h;
			}
		}

		SDL_Window* Window::GetNativeWindow() const {
			return m_Window.get();
		}
	}
}