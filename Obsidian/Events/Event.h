#pragma once

#include <SDL.h>
#define MAX_BUTTON 32

namespace obsidian {
	namespace event {
		class Event {
		private:
			static bool m_KeyHeld[SDL_NUM_SCANCODES];
			static bool m_KeyPressed[SDL_NUM_SCANCODES];
			static bool m_KeyReleased[SDL_NUM_SCANCODES];

			static bool m_MouseHeld[MAX_BUTTON];
			static bool m_MousePressed[MAX_BUTTON];
			static bool m_MouseReleased[MAX_BUTTON];

			static int m_WindowWidth;
			static int m_WindowHeight;

			static bool m_WindowResized;

			static int m_MouseX;
			static int m_MouseY;

			static bool m_QuitRequest;
		public:
			static void Update();
			static bool IsKeyReleased(SDL_Scancode key);
			static bool IsKeyPressed(SDL_Scancode key);
			static bool IsKeyHeld(SDL_Scancode key);
			static bool IsMouseButtonReleased(int button);
			static bool IsMouseButtonPressed(int button);
			static bool IsMouseButtonHeld(int button);
			static void GetMousePositions(int& x, int& y);
			static bool IsWindowResized();
			static void GetWindowSize(int& w, int& h);
			static void ProcessEvent(SDL_Event& event);
			static bool QuitRequest();
		};
	}
}