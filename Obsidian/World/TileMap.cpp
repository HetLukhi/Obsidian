#include "TileMap.h"

namespace obsidian {
	namespace world {
		TileMap::TileMap(renderer::Texture* tileset, int tilewidth, int tileheight) : 
			m_Tileset{ tileset }, m_TileWidth{ tilewidth }, m_TileHeight{tileheight},
			m_MapWidth{ 0 }, m_MapHeight{0}
		{}

		void TileMap::SetMapData(const std::vector<std::vector<int>>& data) {
			m_MapData = data;
			m_MapHeight = data.size();
			m_MapWidth = data[0].size();
		}

		void TileMap::Render(SDL_Renderer* renderer,const renderer::Camera& camera) {
			int startX = (camera.GetPosition().x) / m_TileWidth;
			int startY = (camera.GetPosition().y) / m_TileHeight;
			int endX = (startX + camera.GetViewportWidth()) / m_TileWidth + 1;
			int endY = (startY + camera.GetViewportHeight()) / m_TileHeight + 1;

			startX = std::max(startX, 0);
			startY = std::max(startY, 0);
			endX = std::min(endX, m_MapWidth);
			endY = std::min(endY, m_MapHeight);

			for (int y = startY; y < endY; y++) {
				for (int x = startX; x < endX; x++) {
					int tileID = m_MapData[y][x];
					Tile tile = TileRegistry::GetTile(tileID);
					SDL_Rect destRect = {
						x * m_TileWidth + static_cast<int>(camera.GetOffset().x),
						y * m_TileHeight + static_cast<int>(camera.GetOffset().y),
						m_TileWidth,
						m_TileHeight
					};

					SDL_RenderCopy(renderer, m_Tileset->GetNativeTexture(), &tile.srcRect, &destRect);
				}
			}
		}
		bool TileMap::IsTileSolid(int x, int y) const {
			if (x < 0 || y < 0 || x >= m_MapWidth || y >= m_MapHeight)
				return false;
			int tileID = m_MapData[y][x];
			return TileRegistry::GetTile(tileID).solid;
		}

		bool TileMap::IsTileDangerous(int x, int y) const {
			if (x < 0 || y < 0 || x >= m_MapWidth || y >= m_MapHeight)
				return false;
			int tileID = m_MapData[y][x];
			return TileRegistry::GetTile(tileID).dangerous;
		}
	}
}