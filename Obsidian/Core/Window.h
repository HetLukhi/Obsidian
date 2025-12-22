#pragma once
#include <SDL.h>
#include <memory>
#include <stdexcept>
#include <string>

namespace obsidian {
	namespace core {

		class Window {

		private:
			std::string m_Title;
			int m_Width;
			int m_Height;
			std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_Window;

		public:
			Window();
			Window(const std::string& title, int width, int height);
			~Window();
			int GetWidth() const;
			int GetHeight() const;
			SDL_Window* Get_Native_Window() const;

		private:
			void Window_Init();
		};
	}
}