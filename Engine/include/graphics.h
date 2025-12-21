#pragma once
#include <SDL.h>
#include <memory>
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
			void Window_Init();
			int GetWidth() const;
			int GetHeight() const;
			SDL_Window* Get_Native_Window() const;
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
