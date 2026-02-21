#pragma once
#include <SDL.h>
#include "Core/Window.h"
#include "Color.h"
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

			static Color m_ClearColor;

		public:
			static void Init(const obsidian::core::Window& window);
			static void Shutdown();
			static void BeginFrame();
			static void EndFrame();

			static void SetClearColor(const Color& color);

			static void OnWindowResize(int width, int height);

			static SDL_Renderer* GetNativeRenderer();
		};
	}
}