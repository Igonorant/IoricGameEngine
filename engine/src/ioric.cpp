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

	// Initialize Texture Manager
	texManager.SetRenderer(renderer);

	return IoricError::Success;
}

IoricError Ioric::Quit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return IoricError::Success;
}

unsigned int Ioric::LoadTexture(const char* path)
{
	return texManager.LoadTexture(path);
}

bool Ioric::HandleEvents()
{
	while (SDL_PollEvent(&events)) {
		switch (events.type) {
		case SDL_QUIT:
			return false;
			break;

		case SDL_KEYDOWN:
			if (events.key.keysym.sym == SDLK_ESCAPE)
				return false;
				break;
			if (events.key.keysym.sym == SDLK_LEFT)
				break;
			if (events.key.keysym.sym == SDLK_RIGHT)
				ClearRenderQueue();
				break;
		}
	}
	return true;
}

void Ioric::Update()
{
}


// Methods to test some functionalities
// Not definitive


void Ioric::Render()
{
		SDL_RenderClear(renderer);

		for (unsigned int i = 0; i < rIDs.size(); i++) {
			SDL_RenderCopy(renderer, texManager.GetTexture(rIDs[i]), srcRects[i], dstRects[i]);
		}

		SDL_RenderPresent(renderer);
	}

void Ioric::AddToRenderQueue(unsigned int texID, SDL_Rect* srcRect, SDL_Rect* dstRect)
{
	rIDs.push_back(texID);
	srcRects.push_back(srcRect);
	dstRects.push_back(dstRect);
}

void Ioric::ClearRenderQueue()
{
	rIDs.clear();
	srcRects.clear();
	dstRects.clear();
}
