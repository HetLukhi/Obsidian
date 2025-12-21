#pragma once
#include<SDL.h>
#include <memory>
#include "graphics.h"
#include "input.h"
#include <stdexcept>

namespace obsidian {
	namespace core {
		class Engine {
		private:
			std::unique_ptr<graphics::Renderer> m_Renderer;
			std::unique_ptr<graphics::Window> m_Window;
			
			bool m_Running{ true };
		public:
			Engine();
			~Engine();
			void Run();

		private:
			void Init();
			void Shutdown();
		};
	}
}