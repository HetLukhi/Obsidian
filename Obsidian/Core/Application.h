#pragma once

namespace obsidian {
	namespace core {
		class Application {
		public:
			Application();
			virtual ~Application();

			void Run();
		 };

		Application* CreateApplication();
	}
}