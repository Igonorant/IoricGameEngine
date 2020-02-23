#include"ioric.h"
#include <iostream>

int main(int argc, char* argv[])
{
	Ioric engine;
	IoricError errorHandler = IoricError::Success;

	errorHandler = engine.Init("Ioric Game Engine",640,480);
	
	if (errorHandler == IoricError::Success)
	{
		// Setup
		unsigned int texID = engine.LoadTexture("assets\\texture_test.bmp");
		texID = engine.LoadTexture("assets\\texture_test.bmp");
		texID = engine.LoadTexture("assets\\texture_test.bmp");
		texID = engine.LoadTexture("assets\\texture_test.bmp");
		texID = engine.LoadTexture("assets\\texture_test.bmp");
		
		SDL_Rect char1, char2;
		char1.x = 64;
		char1.y = 64;
		char1.w = 64;
		char1.h = 64;

		char2.x = 128;
		char2.y = 128;
		char2.w = 64;
		char2.h = 64;

		engine.AddToRenderQueue(texID, NULL, &char1);

		texID = engine.LoadTexture("assets\\texture_test2.png");

		engine.AddToRenderQueue(texID, NULL, &char2);

		// Loop
		while (engine.HandleEvents()) {
			engine.Update();
			engine.Render();
			char2.x++;
			SDL_Delay(60);
		}

	}

	//std::cin.get();

	engine.Quit();

	return (int)errorHandler;
}