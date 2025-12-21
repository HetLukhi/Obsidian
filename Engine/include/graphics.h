#pragma once
#include <SDL.h>
#include <memory>
#include <stdexcept>
#include <string>

namespace obsidian {
	namespace graphics {

		class Window {

		private:
			std::string m_Title;
			int m_Width;
			int m_Height;
			std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_Window;

		public:
			Window();
			Window(const std::string& title, int width, int height);
			int GetWidth() const;
			int GetHeight() const;
			SDL_Window* Get_Native_Window() const;

		private:
			void Window_Init();
		};

		class Renderer {
		private:
			std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_Renderer;

		public:
			Renderer();
			void Renderer_Init(const Window& window);
			void BeginFrame();
			void EndFrame();
		};
	}
}
