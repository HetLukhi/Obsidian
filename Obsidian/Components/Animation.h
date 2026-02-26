#pragma once

#include "Sprite.h"
#include <vector>

namespace obsidian {
	namespace components {
		struct Frame {
			SDL_Rect rect;      
			float duration;    
		};
		class Animation {
		public:
			Animation(Sprite* sprite);

			void AddFrame(const SDL_Rect& rect, float duration);
			void Update(float deltaTime);
			void play(bool loop = true);
			void stop();
			void reset();

			bool IsPlaying() const;

		private:
			Sprite* m_Sprite;
			std::vector<Frame> m_Frames;
			size_t m_CurrentFrame;
			float m_ElapsedTime;
			bool m_Playing;
			bool m_Loop;
		};
	}
}