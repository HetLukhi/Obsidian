#include "input.h"

namespace obsidian {
	namespace input {

		bool Input::m_QuitRequest{ false };
		bool Input::m_KeyHeld[SDL_NUM_SCANCODES]{ false };
		bool Input::m_KeyReleased[SDL_NUM_SCANCODES]{ false };
		bool Input::m_KeyPressed[SDL_NUM_SCANCODES]{ false };

		bool Input::m_MouseHeld[MAX_BUTTON]{ false };
		bool Input::m_MousePressed[MAX_BUTTON]{ false };
		bool Input::m_MouseReleased[MAX_BUTTON]{ false };
		int Input::m_MouseX{ 0 };
		int Input::m_MouseY{ 0 };

		bool Input::IsKeyPressed(SDL_Scancode key) {
			return m_KeyPressed[key];
		}
		bool Input::IsKeyReleased(SDL_Scancode key) {
			return m_KeyReleased[key];
		}
		bool Input::IsKeyHeld(SDL_Scancode key) {
			return m_KeyHeld[key];
		}

		bool Input::IsMouseButtonPressed(int button) {
			if (button >= 0 && button < MAX_BUTTON)
				return m_MousePressed[button];
			return false;
		}

		bool Input::IsMouseButtonReleased(int button) {
			if (button >= 0 && button < MAX_BUTTON)
				return m_MouseReleased[button];
			return false;
		}

		bool Input::IsMouseButtonHeld(int button) {
			if (button >= 0 && button < MAX_BUTTON)
				return m_MouseHeld[button];
			return false;
		}

		void Input::Update() {

			for (int i = 0; i < SDL_NUM_SCANCODES; ++i) {
				m_KeyPressed[i] = false;
				m_KeyReleased[i] = false;
			}
			for (int i = 0; i < MAX_BUTTON; ++i) {
				m_MousePressed[i] = false;
				m_MouseReleased[i] = false;
			}
		}

		bool Input::QuitRequest() {
			return m_QuitRequest;
		}

		void Input::GetMousePositions(int& x, int& y) {
			x = m_MouseX;
			y = m_MouseY;
		}

		void Input::ProcessEvent(SDL_Event& event) {
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
			default:
				break;
			}
		}
	}
}