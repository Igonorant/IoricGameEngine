#include "ioric.h"

Ioric::Ioric()
{
}

Ioric::~Ioric()
{
	Quit();
}

IoricError Ioric::Init(const char* title, int width, int height)
{
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return IoricError::SDLInitFail;
	}

	// Load support for the JPG and PNG image formats
	int flags = IMG_INIT_JPG | IMG_INIT_PNG;
	int initted = IMG_Init(flags);
	if ((initted & flags) != flags) {
		SDL_Log("IMG_Init: Failed to init required jpg and png support!\n");
		SDL_Log("IMG_Init: %s\n", IMG_GetError());
		return IoricError::SDLImageInitFail;
	}

	SDL_Log("Initialization of SDL and SDL image successfully!");

	// Create window
	window = SDL_CreateWindow(
		title,							// window title
		SDL_WINDOWPOS_CENTERED,			// initial x position
		SDL_WINDOWPOS_CENTERED,			// initial y position
		width,							// width, in pixels
		height,							// height, in pixels
		SDL_WINDOW_ALLOW_HIGHDPI		// flags
	);
	if (window == NULL)
	{
		SDL_Log("Unable to create window: %s", SDL_GetError());
		return IoricError::SDLCreateWindowFail;
	}

	// Create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		SDL_Log("Unable to create renderer: %s", SDL_GetError());
		return IoricError::SDLCreateRendererFail;
	}



	return IoricError::Success;
}

IoricError Ioric::Quit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return IoricError::Success;
}


// Methods to test some functionalities
// Not definitive

void Ioric::AddTexture(const char* path)
{
	tmpSurface = IMG_Load(path);
	tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

}

void Ioric::Render()
{
	while (1) {
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				break;
			}
		}

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, tmpTexture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(tmpTexture);
}
