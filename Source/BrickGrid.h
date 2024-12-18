#pragma once
#include <fstream>
#include <vector>
#include <string>

#include <iostream> //DEBUG

#include "GameConsts.h"

class Brick;

class BrickGrid
{
public:
	BrickGrid() {}
	~BrickGrid() {}

	void ImportMap(std::string path);
};

