#include "window.h"
#include <string>

namespace obsidian {
	namespace graphics {
		Window::Window() : title{"Window"}, window{nullptr,SDL_DestroyWindow}, renderer{nullptr,SDL_DestroyRenderer} {}

		void Window::window_init() {

			this->window.reset(SDL_CreateWindow(this->title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->width, this->height, 0));
			
			if (!this->window) {
				throw std::runtime_error(std::string("Error creating Window: ") + SDL_GetError());
			}
		}

		SDL_Window* Window::get_native_window() const {
			return this->window.get();
		}

		Renderer::Renderer() : renderer{nullptr,&SDL_DestroyRenderer} {}

		void Renderer::renderer_init(const Window& window) {
			SDL_Window* raw_window = window.get_native_window();
			this->renderer.reset(SDL_CreateRenderer(raw_window, -1, SDL_RENDERER_PRESENTVSYNC));
			if (!this->renderer) {
				throw std::runtime_error(std::string("Error creating Renderer: ") + SDL_GetError());
			}
		}

		void Renderer::clear() {
			SDL_RenderClear(this->renderer.get());
		}

		void Renderer::present() {
			SDL_RenderPresent(this->renderer.get());
		}
	}
}



