#pragma once
#include <SDL.h>
#include "../Core/Window.h"
#include <memory>
#include <stdexcept>
#include <string>

namespace obsidian {
	namespace renderer {
		class Renderer {
		private:
			std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_Renderer;

		public:
			Renderer();
			void Renderer_Init(const obsidian::core::Window& window);
			void BeginFrame();
			void EndFrame();
		};
	}
}