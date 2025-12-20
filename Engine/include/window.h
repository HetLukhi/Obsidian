#pragma once
#include <SDL.h>
#include <memory>
#include <iostream>

namespace obsidian {
	namespace graphics {

		class Window {
		public:
			constexpr static int width{ 800 };
			constexpr static int height{ 600 };

			Window();
			void window_init();
			SDL_Window* get_native_window () const;

		private:
			std::string title;
			std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
			
		};

		class Renderer {
		public:
			Renderer();
			void renderer_init(const Window& window);
			void clear();
			void present();

		private:
			std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer;
		};

	}
}
