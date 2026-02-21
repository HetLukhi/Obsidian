#include "Camera.h"

namespace obsidian {
	namespace renderer {
		Camera::Camera(float viewportWidth, float viewportHeight) :
			m_Position{ 0.0f, 0.0f },
			m_ViewportWidth{ viewportWidth },
			m_ViewportHeight{ viewportHeight }
		{ }

		void Camera::SetPosition(const math::vec2& position){
			m_Position = position;
		}

		void Camera::Move(const math::vec2& delta) {
			m_Position += delta;
		}

		const math::vec2& Camera::GetPosition() const {
			return m_Position;
		}

		float Camera::GetViewportWidth() const {
			return m_ViewportWidth;
		}
		float Camera::GetViewportHeight() const {
			return m_ViewportHeight;
		}
		math::vec2 Camera::GetOffset() const {
			return {-m_Position.x,-m_Position.y};
		}
	}
}