#pragma once
#include "Window.h"

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
		};

		Application* CreateApplication();
	}
}