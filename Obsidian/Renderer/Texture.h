#pragma once
#include <string>
#include <SDL.h>
#include <stdexcept>
#include <SDL_image.h>
#include <memory>

namespace obsidian {
	namespace renderer {
		class Texture {
		public:
			Texture(SDL_Renderer* renderer, const std::string& path);
			~Texture() = default;

			static void Init();
			static void Shutdown();

			SDL_Texture* GetNativeTexture() const;
			inline int GetWidth() const { return m_Width; }
			inline int GetHeight() const { return m_Height; }
		private:
			std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> m_Texture;
			int m_Width;
			int m_Height;
		};
	}
}