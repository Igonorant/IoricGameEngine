#include"ioric.h"
#include <iostream>

int main(int argc, char* argv[])
{
	Ioric engine;
	IoricError errorHandler = IoricError::Success;

	errorHandler = engine.Init("Ioric Game Engine",640,480);
	
	if (errorHandler == IoricError::Success)
	{

		unsigned int texID = engine.LoadTexture("assets\\texture_test.bmp");
		texID = engine.LoadTexture("assets\\texture_test.bmp");
		texID = engine.LoadTexture("assets\\texture_test.bmp");
		texID = engine.LoadTexture("assets\\texture_test.bmp");
		texID = engine.LoadTexture("assets\\texture_test.bmp");
		texID = engine.LoadTexture("assets\\texture_test2.png");
		engine.Render(texID);

	}

	//std::cin.get();

	engine.Quit();

	return (int)errorHandler;
}