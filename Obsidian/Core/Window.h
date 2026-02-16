#pragma once
#include <SDL.h>
#include <memory>
#include <stdexcept>
#include <string>
#include "Events/Event.h"
#include <functional>

namespace obsidian {
	namespace core {

		class Window {

		public:
			using EventCallbackFn = std::function<void(obsidian::event::Event&)>;
			struct WindowProps
			{
				std::string Title;
				unsigned int Width;
				unsigned int Height;

				WindowProps(const std::string& title = "Obsidian Engine",
					unsigned int width = 1280,
					unsigned int height = 720)
					: Title(title), Width(width), Height(height) {
				}
			};

		private:
			struct WindowData {
				std::string Title;
				unsigned int Width;
				unsigned int Height;
			};
			WindowData m_Data;
			std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_Window;

		public:
			Window(const WindowProps& props);

			void OnUpdate();
			
			unsigned int GetWidth() const;
			unsigned int GetHeight() const;
			SDL_Window* GetNativeWindow() const;
			static std::unique_ptr<Window> Create(const WindowProps& props = WindowProps());

		private:
			void Init(const WindowProps& props);
		};
	}
}