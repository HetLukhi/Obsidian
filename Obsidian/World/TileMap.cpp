#include "TileMap.h"

namespace obsidian {
	namespace world {
		TileMap::TileMap(renderer::Texture* tileset, int tilewidth, int tileheight) : 
			m_Tileset{ tileset },m_MapWidth{ 0 }, m_MapHeight{0}
		{}

		void TileMap::SetLayerData(int layerIndex,const std::vector<std::vector<int>>& data) {
			if (layerIndex >= m_Layers.size()) {
				m_Layers.resize(layerIndex + 1);
			}
			if (m_MapWidth == 0 && m_MapHeight == 0)
			{
				m_MapHeight = data.size();
				m_MapWidth = data[0].size();
			}
			if (data.size() != m_MapHeight || data[0].size() != m_MapWidth)
			{
				return;
			}
			m_Layers[layerIndex].m_MapData = data;
		}

		void TileMap::AddLayer(const Layer& layer) {
			m_Layers.push_back(layer);
		}

		void TileMap::Render(SDL_Renderer* renderer,const renderer::Camera& camera,float deltaTime) {
			for (const Layer& layer : m_Layers) {
			int startX = (camera.GetPosition().x) / layer.tileWidth;
			int startY = (camera.GetPosition().y) / layer.tileHeight;
			int endX = (camera.GetPosition().x + camera.GetViewportWidth()) / layer.tileWidth + 1;
			int endY = (camera.GetPosition().y + camera.GetViewportHeight()) / layer.tileHeight + 1;

			int layerWidth = layer.m_MapData[0].size();
			int layerHeight = layer.m_MapData.size();

			startX = std::max(startX, 0);
			startY = std::max(startY, 0);
			endX = std::min(endX, layerWidth);
			endY = std::min(endY, layerHeight);

			
			
				for (int y = startY; y < endY; y++) {
					for (int x = startX; x < endX; x++) {
						int tileID = layer.m_MapData[y][x];
						if (tileID < 0)
							continue;
						if (!TileRegistry::HasTile(tileID))
							continue;
						const Tile& tile = TileRegistry::GetTile(tileID);

						SDL_Rect srcRect = tile.srcRect;
						if (tile.animation)
							srcRect = tile.animation->GetCurrentFrameRect();

						SDL_Rect destRect = {
							x * layer.tileWidth + static_cast<int>(camera.GetOffset().x),
							y * layer.tileHeight + static_cast<int>(camera.GetOffset().y),
							layer.tileWidth,
							layer.tileHeight
						};

						SDL_RenderCopy(renderer, m_Tileset->GetNativeTexture(), &srcRect, &destRect);
					}
				}
			}
		}
		bool TileMap::IsTileSolid(int x, int y) const {

			if (x < 0 || y < 0 || x >= m_MapWidth || y >= m_MapHeight)
				return false;
			for (const Layer& layer : m_Layers) {
				int tileID = layer.m_MapData[y][x];
				if (tileID < 0)
					continue;
				if (TileRegistry::GetTile(tileID).solid)
					return true;
			}
			return false;
		}

		int TileMap::WorldToTileX(float x,const Layer& layer) const{
			return static_cast<int>(std::floor(x / layer.tileWidth));
		}

		int TileMap::WorldToTileY(float y, const Layer& layer) const{
			return static_cast<int>(std::floor(y / layer.tileHeight));
		}

		bool TileMap::IsTileDangerous(int x, int y) const {

			if (x < 0 || y < 0 || x >= m_MapWidth || y >= m_MapHeight)
				return false;
			for (const Layer& layer : m_Layers) {
				int tileID = layer.m_MapData[y][x];
				if (tileID < 0)
					continue;
				if (TileRegistry::GetTile(tileID).dangerous)
					return true;
			}
			return false;
		}
	}
}