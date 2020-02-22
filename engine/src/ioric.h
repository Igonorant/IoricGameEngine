#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "ioric_error.h"

class Ioric
{

public:
	Ioric();
	~Ioric();

	IoricError Init(const char* title, int width, int height);
	IoricError Quit();


	// Methods to test some functionalities
	// Not definitive
	void AddTexture(const char* path);
	void Render();

private:
	
private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	// Variables to test some functionalities
	// Not definitive
	SDL_Surface* tmpSurface = NULL;
	SDL_Texture* tmpTexture = NULL;
};