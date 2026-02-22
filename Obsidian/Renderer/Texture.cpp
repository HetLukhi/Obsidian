#include "Texture.h"

namespace obsidian {
	namespace renderer {
		Texture::Texture(SDL_Renderer* renderer, const std::string& path) :
			m_Texture(nullptr, SDL_DestroyTexture), m_Width{ 0 }, m_Height{ 0 }
		{
			SDL_Texture* texture = IMG_LoadTexture(renderer,path.c_str());
			if (!texture) {
				throw std::runtime_error(std::string("Error creating Texture: ") + SDL_GetError());
			}
			m_Texture.reset(texture);
			SDL_QueryTexture(texture, nullptr, nullptr, &m_Width, &m_Height);
		}

		SDL_Texture* Texture::GetNativeTexture() const {
			return m_Texture.get();
		}

		int Texture::GetWidth() const {
			return m_Width;
		}
		int Texture::GetHeight() const {
			return m_Height;
		}
	}
}