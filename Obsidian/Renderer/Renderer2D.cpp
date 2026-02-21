#include "Renderer2D.h"

namespace obsidian {
	namespace renderer {
		void Renderer2D::Init() {
			m_CameraOffset = { 0.0f,0.0f };
		}

		void Renderer2D::Shutdown() {

		}

		void Renderer2D::BeginScene(const Camera& camera) {
			m_CameraOffset = camera.GetOffset();
		}

		void Renderer2D::EndScene() {

		}

		void Renderer2D::DrawQuad(const math::vec2& position, const math::vec2& size) {
			SDL_Renderer* renderer = Renderer::GetNativeRenderer();
			math::vec2 screenPos = position + m_CameraOffset;

			SDL_Rect rect;
			rect.x = static_cast<int>(screenPos.x);
			rect.y = static_cast<int>(screenPos.y);
			rect.w = static_cast<int>(size.x);
			rect.h = static_cast<int>(size.y);

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderFillRect(renderer, &rect);
		}

		void Renderer2D::DrawQuad(const math::vec2& position, const math::vec2& size, const Color& color) {
			SDL_Renderer* renderer = Renderer::GetNativeRenderer();
			math::vec2 screenPos = position + m_CameraOffset;

			SDL_Rect rect;
			rect.x = static_cast<int>(screenPos.x);
			rect.y = static_cast<int>(screenPos.y);
			rect.w = static_cast<int>(size.x);
			rect.h = static_cast<int>(size.y);

			SDL_SetRenderDrawColor(renderer, color.r,color.g,color.b,color.a);
			SDL_RenderFillRect(renderer, &rect);
		}
	}
}