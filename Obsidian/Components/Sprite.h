#pragma once 

#include "Renderer/Texture.h"
#include "Maths/Vec2.h"
#include "Renderer/Camera.h"

namespace obsidian {
	namespace components {
		class Sprite {
		private:
			renderer::Texture* m_Texture;
			SDL_Rect m_SourceRect;
			SDL_Rect m_DestRect;
			double m_Angle;
			bool m_FlipHorizontal;
			bool m_FlipVertical;
		public:
			Sprite();

			void SetTexture(renderer::Texture* texture);
			void SetSourceRect(const SDL_Rect& rect);
			void SetPosition(const math::vec2& position);
			void SetSize(const math::vec2& size);
			void SetFlip(bool horizontal, bool vertical);
			void SetAngle(double angle);
			void Draw(SDL_Renderer* renderer, const renderer::Camera& camera);
		};
	}
}