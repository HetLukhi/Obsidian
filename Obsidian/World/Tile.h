#pragma once 
#include <SDL.h>

namespace obsidian {
	namespace world {
		struct Tile {
			SDL_Rect srcRect;
			bool solid;
			bool dangerous;
		};
	}
}