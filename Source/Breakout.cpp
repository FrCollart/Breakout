// Breakout.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

#include "SFMLTest.h"
#include "App.h"

int main() {
	std::unique_ptr<App> app = std::make_unique<App>();
	app->Run();

    return EXIT_SUCCESS;
}
