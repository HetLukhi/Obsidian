#include "Renderer/Renderer.h"

namespace obsidian {
	namespace renderer {
		Renderer::RendererPtr Renderer::m_Renderer{ nullptr, SDL_DestroyRenderer };
		uint8_t Renderer::m_ClearR = 0;
		uint8_t Renderer::m_ClearG = 0;
		uint8_t Renderer::m_ClearB = 0;
		uint8_t Renderer::m_ClearA = 255;

			void Renderer::Init(const obsidian::core::Window& window) {
				SDL_Window* raw_window = window.GetNativeWindow();
				m_Renderer.reset(SDL_CreateRenderer(raw_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
				if (!m_Renderer) {
					throw std::runtime_error(std::string("Error creating Renderer: ") + SDL_GetError());
				}
			}

			void Renderer::Shutdown() {
				if (m_Renderer) m_Renderer.reset();
			}

			void Renderer::BeginFrame() {
				SDL_SetRenderDrawColor(m_Renderer.get(),m_ClearR, m_ClearG, m_ClearB, m_ClearA);
				SDL_RenderClear(m_Renderer.get());
			}

			void Renderer::EndFrame() {
				SDL_RenderPresent(m_Renderer.get());
			}

			void Renderer::SetClearColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
				m_ClearR = r;
				m_ClearG = g;
				m_ClearB = b;
				m_ClearA = a;
			}

			void Renderer::Clear(){
				SDL_RenderClear(m_Renderer.get());
			}
	}
}