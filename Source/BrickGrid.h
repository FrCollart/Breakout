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

	void AddBrick(std::shared_ptr<class Brick> brick);
	void RemoveBrick(std::shared_ptr<class Brick> brick);
	void ImportMap(std::string path);

private:
	std::vector<std::shared_ptr<class Brick>> m_Bricks;
};

