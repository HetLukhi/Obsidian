#pragma once

#include "Renderer/Texture.h"
#include "Tile.h"
#include "Renderer/Camera.h"
#include "TileRegistry.h"
#include <vector>
#include <algorithm>

namespace obsidian {
	namespace world {

		struct Layer {
			std::vector<std::vector<int>> m_MapData;
			int tileWidth;
			int tileHeight;

			int layerWidth;
			int layerHeight;
		};

		class TileMap {
		public:
			TileMap(renderer::Texture* tileset, int tilewidth, int tileheight);
			void SetLayerData(int layerIndex,const std::vector<std::vector <int>>& data);

			void AddLayer(const Layer& layer);

			void Render(SDL_Renderer* renderer, const renderer::Camera& camera, float deltaTime);

			bool IsTileSolid(const math::vec2& position) const;
			bool IsTileDangerous(const math::vec2& position) const;

			int WorldToTileX(float x, const Layer& layer) const;
			int WorldToTileY(float y, const Layer& layer) const;

			inline int GetMapWidth() const { return m_MapWidth; }
			inline int GetMapHeight() const { return m_MapHeight; }

		private:
			renderer::Texture* m_Tileset;

			int m_MapWidth;
			int m_MapHeight;

			std::vector<Layer> m_Layers;
		};
	}
}