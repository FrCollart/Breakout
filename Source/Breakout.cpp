// Breakout.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

#include "SFMLTest.h"
#include "App.h"

int main() {
    
	// Uncomment this to test if SFML is working correctly
	
    try
    {
		SFMLTest::Run();
	}
	catch (const std::exception& e)
	{
		std::cerr << "SFML is not installed correctly, please check your installation" << std::endl;
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	

	std::unique_ptr<App> app = std::make_unique<App>();
	app->Run();

    return EXIT_SUCCESS;
}
