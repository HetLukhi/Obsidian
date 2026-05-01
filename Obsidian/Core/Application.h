#pragma once
#include "Window.h"
#include "Events/Event.h"
#include "Renderer/Renderer.h"
#include "Renderer/Camera.h"
#include <memory>
#include<iostream>

namespace obsidian {
	namespace core {
		class Application {
		public:
			Application();
			virtual ~Application();
			void Run();

			Window* GetWindow() { return m_Window.get(); }

			virtual void OnUpdate(float deltaTime) = 0;
			virtual void OnRender() = 0;

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