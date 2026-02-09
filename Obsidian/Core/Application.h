#pragma once
#include "Window.h"
#include "Event.h"
#include "Renderer.h"
#include <iostream>

namespace obsidian {
	namespace core {
		class Application {
		public:
			Application();
			virtual ~Application();
			void Run();

		private:
			std::unique_ptr<obsidian::core::Window> m_Window;
			std::unique_ptr<obsidian::renderer::Renderer> m_Renderer;
			bool m_Running = true;
			void Init();
			void Shutdown();
		};

		Application* CreateApplication();
	}
}