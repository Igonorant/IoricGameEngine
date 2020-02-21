#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

int main(int argc, char* argv[])
{
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return 1;
	}

	// Load support for the JPG and PNG image formats
	int flags = IMG_INIT_JPG | IMG_INIT_PNG;
	int initted = IMG_Init(flags);
	if ((initted & flags) != flags) {
		SDL_Log("IMG_Init: Failed to init required jpg and png support!\n");
		SDL_Log("IMG_Init: %s\n", IMG_GetError());
		SDL_Quit();
		return 2;
	}

	SDL_Log("Initialization of SDL and SDL image successfully!");

	std::cin.get();
	SDL_Quit();
	return 0;
}