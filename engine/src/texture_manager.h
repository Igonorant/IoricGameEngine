#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "ioric_error.h"
#include <vector>

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	unsigned int LoadTexture(const char* path);
	unsigned int GetID(const char* path);
	SDL_Texture* GetTexture(const unsigned int ID);
	SDL_Texture* GetTexture(const char* path);

	void SetRenderer(SDL_Renderer* rend);

private:

	struct TextureObject {
		TextureObject(unsigned int ID, const char* path, SDL_Texture* texture)
			:
			ID(ID),
			path(path),
			texture(texture)
		{}

		unsigned int ID; // also works as vector index
		const char* path;
		SDL_Texture* texture;
	};

	std::vector<TextureObject> textures;
	unsigned int lastID = 0; // also works as vector index
	SDL_Surface* tmpSurface = NULL;
	SDL_Texture* tmpTexture = NULL;
	SDL_Renderer* renderer = NULL;
};