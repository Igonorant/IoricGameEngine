#include "texture_manager.h"

TextureManager::TextureManager()
{
	SDL_Texture* tmpTex = NULL;
	textures.emplace_back(0, "", tmpTex);
}

TextureManager::~TextureManager()
{
	// Destroy all textures
	for (auto it = textures.begin();
		it != textures.end();
		it++)
	{
		SDL_DestroyTexture((*it).texture);
	}
}

unsigned int TextureManager::LoadTexture(const char* path)
{
	unsigned int tmpID = GetID(path);
	//// Check if texture is already loaded
	//for(auto it = textures.begin();
	//	it != textures.end();
	//	it++)
	//{
	//	if (!strcmp(path, (*it).path))
	//	{
	//		// If texture is already loaded, return ID
	//		return (*it).ID;
	//	}
	//}

	// If texture was not loaded already, load texture and return ID
	if(tmpID)
	{
		return tmpID;
	}
	else
	{
		tmpSurface = IMG_Load(path);
		if (!tmpSurface == NULL)
		{
			tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
			if (!tmpTexture == NULL)
			{
				lastID++;
				textures.emplace_back(lastID, path, tmpTexture);

				tmpTexture = NULL;
				SDL_FreeSurface(tmpSurface);
				tmpSurface = NULL;
				return lastID;

			}
			SDL_FreeSurface(tmpSurface);
			tmpSurface = NULL;
		}
	}

	// Return ID 0 (NULL texture) if everything goes wrong
	return 0;
}

unsigned int TextureManager::GetID(const char* path)
{
	// Find ID corresponding to the given path
	for (auto it = textures.begin();
		it != textures.end();
		it++)
	{
		if (!strcmp(path, (*it).path))
		{
			// If texture is already loaded, return  current ID
			return (*it).ID;
		}
	}

	// Return ID 0 (NULL texture) if everything goes wrong
	return 0;
}

SDL_Texture* TextureManager::GetTexture(const unsigned int ID)
{
	if(ID<=lastID)
	{
		return textures[ID].texture;
	}

	return 0;
	
}

SDL_Texture* TextureManager::GetTexture(const char* path)
{
	return textures[GetID(path)].texture;
}

void TextureManager::SetRenderer(SDL_Renderer* rend)
{
	renderer = rend;
}
