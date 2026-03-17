#include "TileRegistry.h"


namespace obsidian {
	namespace world {

		std::unordered_map<int, Tile> TileRegistry::m_TileDefs;

		void TileRegistry::RegisterTile(int id, const Tile& tileDef) {
			m_TileDefs[id] = tileDef;
		}

		void TileRegistry::UpdateAnimation(float deltaTime) {
			std::unordered_set<components::Animation*> updated;

			for (auto& [id, tile] : m_TileDefs) {
				if (tile.animation && updated.find(tile.animation) == updated.end()) {
					tile.animation->Update(deltaTime);
					updated.insert(tile.animation);
				}
			}
		}

		bool TileRegistry::HasTile(int tileID) {
			return m_TileDefs.find(tileID) != m_TileDefs.end();
		}
	}
}
