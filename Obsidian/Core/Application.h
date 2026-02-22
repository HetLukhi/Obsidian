#pragma once
#include "Window.h"
#include "Events/Event.h"
#include "Renderer/Renderer.h"
#include "Renderer/Renderer2D.h"
#include "Renderer/Camera.h"
#include "Renderer/Color.h"
#include <memory>
#include<iostream>

namespace obsidian {
	namespace core {
		class Application {
		public:
			Application();
			virtual ~Application();
			void Run();

		private:
			std::unique_ptr<obsidian::core::Window> m_Window;
			bool m_Running = true;
			void Init();
			void Shutdown();
			void OnEvent(renderer::Camera& camera);
		};

		Application* CreateApplication();
	}
}