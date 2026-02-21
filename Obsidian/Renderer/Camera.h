#pragma once
#include "Maths\Vec2.h"

namespace obsidian {
	namespace renderer {
		class Camera {
		private:
			obsidian::math::vec2 m_Position;
			float m_ViewportWidth;
			float m_ViewportHeight;

		public:
			Camera(float viewportWidth, float viewportHeight);

			void SetPosition(const math::vec2& position);
			void Move(const math::vec2& delta);

			const math::vec2& GetPosition() const;

			float GetViewportWidth() const;
			float GetViewportHeight() const;

			math::vec2 GetOffset() const;
		};
	}
}