#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "ioric_error.h"
#include "texture_manager.h"

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
	void Render(unsigned int ID);

private:
	
private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	TextureManager texManager;

	// Variables to test some functionalities
	// Not definitive
	SDL_Surface* tmpSurface = NULL;
};