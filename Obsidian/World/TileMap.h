#pragma once

#include "Renderer/Texture.h"
#include "Tile.h"
#include "Renderer/Camera.h"
#include "TileRegistry.h"
#include <vector>
#include <algorithm>

namespace obsidian {
	namespace world {
		class TileMap {
		public:
			TileMap(renderer::Texture* tileset,int tilewidth,int tileheight);
			void SetMapData(const std::vector<std::vector <int>>& data);

			void Render(SDL_Renderer* renderer,const renderer::Camera& camera);

			bool IsTileSolid(int x,int y) const;
			bool IsTileDangerous(int x, int y) const;

			inline int GetMapWidth() const { return m_MapWidth; }
			inline int GetMapHeight() const { return m_MapHeight; }

		private:
			renderer::Texture* m_Tileset;

			int m_TileWidth;
			int m_TileHeight;

			int m_MapWidth;
			int m_MapHeight;

			std::vector<std::vector <int>> m_MapData;

		};
	}
}