#include "Animation.h"

namespace obsidian {
	namespace components {
		Animation::Animation(Sprite* sprite) : m_Sprite(sprite),m_CurrentFrame(0),m_ElapsedTime(0.0f),m_Playing(false),m_Loop(true) {}

		void Animation::AddFrame(const SDL_Rect& rect, float duration) {
			m_Frames.push_back({rect,duration});
		}


		void Animation::Play(bool loop) {
			if (m_Frames.empty()) return;

			m_Playing = true;
			m_Loop = loop;
			m_CurrentFrame = 0;
			m_ElapsedTime = 0.0f;

			m_Sprite->SetSourceRect(m_Frames[0].rect);

		}

		void Animation::Stop() {
			m_Playing = false;
		}

		void Animation::Reset() {
			if (m_Frames.empty()) return;

			m_CurrentFrame = 0;
			m_ElapsedTime = 0.0f;
			m_Sprite->SetSourceRect(m_Frames[0].rect);
		}

		bool Animation::IsPlaying() const {
			return m_Playing;
		}

		SDL_Rect Animation::GetCurrentFrameRect() const {
			if (m_Frames.empty()) {
				return { 0, 0, 0, 0 };
			}
			return m_Frames[m_CurrentFrame].rect;
		}

		void Animation::Update(float deltaTime) {
			if (!m_Playing || m_Frames.empty())
				return;

			m_ElapsedTime += deltaTime;
			while (m_ElapsedTime >= m_Frames[m_CurrentFrame].duration) {
				m_ElapsedTime -= m_Frames[m_CurrentFrame].duration;
				m_CurrentFrame++;

				if (m_CurrentFrame >= m_Frames.size()) {
					if (m_Loop) {
						m_CurrentFrame = 0;
					}
					else {
						m_CurrentFrame = m_Frames.size() - 1;
						m_Playing = false;
						break;
					}
				}
				m_Sprite->SetSourceRect(m_Frames[m_CurrentFrame].rect);
			}
		}
	}
}