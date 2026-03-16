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
			void SetViewportSize(float w,float h);
			inline float GetViewportWidth() const { return m_ViewportWidth; }
			inline float GetViewportHeight() const { return m_ViewportHeight; }

			math::vec2 GetOffset() const;
		};
	}
}