#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include "Renderer/Texture.h"

namespace obsidian {
	namespace assets {
		class AssetManager {
		public:

			static renderer::Texture* LoadTexture(SDL_Renderer* renderer, const std::string& path);
			static void Clear();
			
		private:

			static std::unordered_map<std::string, std::unique_ptr<renderer::Texture>> s_Texture;

		};
	}
}