#include "AssetManager.h"

namespace obsidian {
	namespace assets {
		
		std::unordered_map<std::string, std::unique_ptr<renderer::Texture>> AssetManager::s_Texture;

		renderer::Texture* AssetManager::LoadTexture(SDL_Renderer* renderer, const std::string& path){
			if (s_Texture.find(path) != s_Texture.end()) {
				return s_Texture[path].get();
			}

			s_Texture[path] = std::make_unique<renderer::Texture>(renderer, path);
			return s_Texture[path].get();
		}

		void AssetManager::Clear() {
			s_Texture.clear();
		}
	
	}
}