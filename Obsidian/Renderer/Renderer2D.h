#pragma once
#include "Maths/Vec2.h"
#include "Camera.h"
#include "Renderer.h"

namespace obsidian {
	namespace renderer {
		class Renderer2D {
		public:
			static void Init();
			static void Shutdown();
			static void BeginScene(const Camera& camera);
			static void EndScene();
			static void DrawQuad(const math::vec2& position, const math::vec2& size);
			static void DrawQuad(const math::vec2& position, const math::vec2& size, const Color& color);
			static void SetClearColor(const Color& color);
		private:
			static math::vec2 m_CameraOffset;
			static Color m_ClearColor;
		};
	}
}