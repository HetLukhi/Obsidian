#include "Sprite.h"

namespace obsidian {
	namespace components {

		Sprite::Sprite() : m_Texture(nullptr), m_FlipHorizontal(false), m_FlipVertical(false) {
			m_SourceRect = { 0, 0, 0, 0 };
			m_DestRect = { 0, 0, 0, 0 };
		}

		void Sprite::SetTexture(renderer::Texture* texture) {
			m_Texture = texture;
		}

		void Sprite::SetSourceRect(const SDL_Rect& rect) {
			m_SourceRect = rect;
		}

		void Sprite::SetPosition(const math::vec2& position) {
			m_DestRect.x = static_cast<int>(position.x);
			m_DestRect.y = static_cast<int>(position.y);
		}

		void Sprite::SetSize(const math::vec2& size) {
			m_DestRect.w = static_cast<int>(size.x);
			m_DestRect.h = static_cast<int>(size.y);
		}

		void Sprite::SetFlip(bool horizontal, bool vertical) {
			m_FlipHorizontal = horizontal;
			m_FlipVertical = vertical;
		}

		void Sprite::Draw(SDL_Renderer* renderer, const renderer::Camera& camera) {

			if (!m_Texture)
				return;
			math::vec2 offset = camera.GetOffset();

			SDL_Rect renderRect = m_DestRect;

			renderRect.x += static_cast<int>(offset.x);
			renderRect.y += static_cast<int>(offset.y);

			SDL_RendererFlip flip = SDL_FLIP_NONE;

			if (m_FlipHorizontal) {
				flip = SDL_RendererFlip(flip | SDL_FLIP_HORIZONTAL);
			}
			if (m_FlipVertical) {
				flip = SDL_RendererFlip(flip | SDL_FLIP_VERTICAL);
			}
			SDL_RenderCopyEx(renderer, m_Texture->GetNativeTexture(),&m_SourceRect,&renderRect ,0.0, nullptr, flip);
		}
	}
}