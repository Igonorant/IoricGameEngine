#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "ioric_error.h"
#include "texture_manager.h"
#include <vector>

class Ioric
{

public:
	Ioric();
	~Ioric();

	IoricError Init(const char* title, int width, int height);
	IoricError Quit();

	unsigned int LoadTexture(const char* path);


	// Methods to test some functionalities
	// Not definitive
	bool HandleEvents();
	void Update();
	void Render();

	void AddToRenderQueue(unsigned int texID, SDL_Rect* srcRect, SDL_Rect* dstRect);
	void ClearRenderQueue();

private:
	

private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	TextureManager texManager;
	SDL_Event events;
	std::vector<unsigned int> rIDs;
	std::vector<SDL_Rect*> srcRects, dstRects;

	// Variables to test some functionalities
	// Not definitive
	SDL_Surface* tmpSurface = NULL;
	
};