#include "Renderer.h"

namespace obsidian {
	namespace renderer {
			Renderer::Renderer() : m_Renderer{ nullptr,&SDL_DestroyRenderer } {}

			void Renderer::Renderer_Init(const obsidian::core::Window& window) {
				SDL_Window* raw_window = window.Get_Native_Window();
				m_Renderer.reset(SDL_CreateRenderer(raw_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
				if (!m_Renderer) {
					throw std::runtime_error(std::string("Error creating Renderer: ") + SDL_GetError());
				}
			}

			void Renderer::BeginFrame() {
				SDL_SetRenderDrawColor(m_Renderer.get(), 0, 0, 0, 255);
				SDL_RenderClear(m_Renderer.get());
			}

			void Renderer::EndFrame() {
				SDL_RenderPresent(m_Renderer.get());
			}
	}
}