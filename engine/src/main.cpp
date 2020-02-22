#include"ioric.h"
#include <iostream>

int main(int argc, char* argv[])
{
	Ioric engine;
	IoricError errorHandler = IoricError::Success;

	errorHandler = engine.Init("Ioric Game Engine",640,480);
	
	if (errorHandler == IoricError::Success)
	{

		engine.AddTexture("assets\texture_test.bmp");
		engine.Render();

	}

	std::cin.get();

	engine.Quit();

	return (int)errorHandler;
}