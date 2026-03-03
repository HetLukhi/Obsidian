#pragma once
#include <unordered_map>
#include "Tile.h"

namespace obsidian {
	namespace world {
		class TileRegistry {
		public:
			static void RegisterTile(int id, const Tile& tileDef);
			inline static Tile GetTile(int id) { return m_TileDefs[id]; }

		private:
			static std::unordered_map<int, Tile> m_TileDefs;
		};
	}
}