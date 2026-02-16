#include "Event.h"

namespace obsidian {
	namespace event {

		bool Event::m_QuitRequest{ false };
		bool Event::m_KeyHeld[SDL_NUM_SCANCODES]{ false };
		bool Event::m_KeyReleased[SDL_NUM_SCANCODES]{ false };
		bool Event::m_KeyPressed[SDL_NUM_SCANCODES]{ false };

		bool Event::m_MouseHeld[MAX_BUTTON]{ false };
		bool Event::m_MousePressed[MAX_BUTTON]{ false };
		bool Event::m_MouseReleased[MAX_BUTTON]{ false };
		int Event::m_MouseX{ 0 };
		int Event::m_MouseY{ 0 };

		bool Event::m_WindowResized{ false };
		int Event::m_WindowHeight{ 0 };
		int Event::m_WindowWidth{ 0 };

		bool Event::IsKeyPressed(SDL_Scancode key) {
			return m_KeyPressed[key];
		}
		bool Event::IsKeyReleased(SDL_Scancode key) {
			return m_KeyReleased[key];
		}
		bool Event::IsKeyHeld(SDL_Scancode key) {
			return m_KeyHeld[key];
		}

			bool Event::IsMouseButtonPressed(int button) {
			if (button >= 0 && button < MAX_BUTTON)
				return m_MousePressed[button];
			return false;
		}

		bool Event::IsMouseButtonReleased(int button) {
			if (button >= 0 && button < MAX_BUTTON)
				return m_MouseReleased[button];
			return false;
		}

		bool Event::IsMouseButtonHeld(int button) {
			if (button >= 0 && button < MAX_BUTTON)
				return m_MouseHeld[button];
			return false;
		}

		void Event::Update() {

			Event::m_WindowResized = false;

			for (int i = 0; i < SDL_NUM_SCANCODES; ++i) {
				m_KeyPressed[i] = false;
				m_KeyReleased[i] = false;
			}
			for (int i = 0; i < MAX_BUTTON; ++i) {
				m_MousePressed[i] = false;
				m_MouseReleased[i] = false;
			}
		}

		bool Event::QuitRequest() {
			return m_QuitRequest;
		}

		void Event::GetMousePositions(int& x, int& y) {
			x = m_MouseX;
			y = m_MouseY;
		}

		bool Event::IsWindowResized() {
			return m_WindowResized;
		}

		void Event::GetWindowSize(int& w, int& h) {
			w = m_WindowWidth;
			h = m_WindowHeight;
		}
		void Event::PollEvent() {
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				obsidian::event::Event::ProcessEvent(event);
			}
		}

		void Event::ProcessEvent(SDL_Event& event) {
			switch (event.type) {
			case SDL_QUIT:
				m_QuitRequest = true;
				break;
			case SDL_KEYDOWN: {
				SDL_Scancode sc = event.key.keysym.scancode;
				if (!m_KeyHeld[sc]) {
					m_KeyPressed[sc] = true;
				}
				m_KeyHeld[sc] = true;
				break;
			}
			case SDL_KEYUP: {
				SDL_Scancode sc = event.key.keysym.scancode;
				m_KeyReleased[sc] = true;
				m_KeyHeld[sc] = false;
				break;
			}
			case SDL_MOUSEBUTTONDOWN: {
				Uint8 btn = event.button.button;
				if (btn < MAX_BUTTON) {
					if (!m_MouseHeld[btn]) m_MousePressed[btn] = true;
					m_MouseHeld[btn] = true;
				}
				break;
			}
			case SDL_MOUSEBUTTONUP: {
				Uint8 btn = event.button.button;
				if (btn < MAX_BUTTON) {
					m_MouseReleased[btn] = true;
					m_MouseHeld[btn] = false;
				}
				break;
			}
			case SDL_MOUSEMOTION:
				m_MouseX = event.motion.x;
				m_MouseY = event.motion.y;
				break;
			case SDL_WINDOWEVENT:
				if (event.window.event == SDL_WINDOWEVENT_RESIZED || event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
					m_WindowResized = true;
					m_WindowWidth = event.window.data1;
					m_WindowHeight = event.window.data2;
				}
				break;
			default:
				break;
			}
		}
	}
}