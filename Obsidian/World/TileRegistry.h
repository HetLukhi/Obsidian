#pragma once
#include <unordered_map>
#include <unordered_set>
#include "Tile.h"
#include "Components/Animation.h"

namespace obsidian {
	namespace world {
		class TileRegistry {
		public:
			static void RegisterTile(int id, const Tile& tileDef);
			inline static Tile GetTile(int id) { return m_TileDefs[id]; }
			static void UpdateAnimation(float deltaTime);
			static bool HasTile(int tileID);

		private:
			static std::unordered_map<int, Tile> m_TileDefs;
		};
	}
}