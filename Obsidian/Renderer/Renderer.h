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
			using RendererPtr =
				std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>;

			static RendererPtr m_Renderer;

			static uint8_t m_ClearR;
			static uint8_t m_ClearG;
			static uint8_t m_ClearB;
			static uint8_t m_ClearA;

		public:
			static void Init(const obsidian::core::Window& window);
			static void Shutdown();
			static void BeginFrame();
			static void EndFrame();

			static void SetClearColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
			static void Clear();
		};
	}
}