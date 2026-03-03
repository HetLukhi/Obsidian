#include "TileRegistry.h"


namespace obsidian {
	namespace world {

		std::unordered_map<int, Tile> TileRegistry::m_TileDefs;

		void TileRegistry::RegisterTile(int id, const Tile& tileDef) {
			m_TileDefs[id] = tileDef;
		}
	}
}
