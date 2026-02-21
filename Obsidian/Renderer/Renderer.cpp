#include "Renderer/Renderer.h"

namespace obsidian {
	namespace renderer {

		Color Renderer::m_ClearColor = Color(0, 0, 0, 255);

		Renderer::RendererPtr Renderer::m_Renderer{ nullptr, SDL_DestroyRenderer };

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
				SDL_SetRenderDrawColor(m_Renderer.get(),m_ClearColor.r, m_ClearColor.g, m_ClearColor.b, m_ClearColor.a);
				SDL_RenderClear(m_Renderer.get());
			}

			void Renderer::EndFrame() {
				SDL_RenderPresent(m_Renderer.get());
			}

			void Renderer::SetClearColor(const Color& color) {
				m_ClearColor.r = color.r;
				m_ClearColor.g = color.g;
				m_ClearColor.b = color.b;
				m_ClearColor.a = color.a;
			}

			void Renderer::OnWindowResize(int width, int height) {
				SDL_RenderSetViewport(m_Renderer.get(), nullptr);
			}
			
			SDL_Renderer* Renderer::GetNativeRenderer() {
				return m_Renderer.get();
			}
	}
}