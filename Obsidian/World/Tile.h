#pragma once 
#include <SDL.h>
#include "Components/Animation.h"

namespace obsidian {
	namespace world {
		struct Tile {
			SDL_Rect srcRect;
			bool solid;
			bool dangerous;

			components::Animation* animation;
		};
	}
}