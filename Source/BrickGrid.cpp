#include "BrickGrid.h"

#include <sstream>

#include "Brick.h"
#include "GameConsts.h"
#include "EntityManager.h"

void BrickGrid::ImportMap(std::string path)
{
	std::ifstream importFile(path);
	if (!importFile.is_open())
	{
		std::cerr << "Failed to open file: " << path << std::endl;
		return;
	}

	int gridColumns, gridRows;

	std::string currentLine; if (std::getline(importFile, currentLine))
	{
		std::istringstream dimensionStream(currentLine);
		dimensionStream >> gridColumns >> gridRows;
	}
	else
	{
		std::cerr << "File is empty or invalid format." << std::endl;
		return;
	}

	const int BRICK_WIDTH = (GRID_WIDTH - (gridColumns - 1) * GRID_INTER) / gridColumns;
	const int BRICK_HEIGHT = (GRID_HEIGHT - (gridRows - 1) * GRID_INTER) / gridRows;

	if (BRICK_WIDTH <= 0 || BRICK_HEIGHT <= 0)
	{
		std::cerr << "Invalid dimensions: GRID_WIDTH or GRID_HEIGHT too small for grid configuration." << std::endl;
		return;
	}

	int rowIndex = 0;
	while (std::getline(importFile, currentLine))
	{
		for (int colIndex = 0; colIndex < currentLine.size(); ++colIndex)
		{
			if (currentLine[colIndex] == 'X')
			{
				int x = colIndex * (BRICK_WIDTH + GRID_INTER) + GRID_X;
				int y = rowIndex * (BRICK_HEIGHT + GRID_INTER) + GRID_Y;

				auto brick = std::make_shared<Brick>((float)x, (float)y, (float)BRICK_WIDTH, (float)BRICK_HEIGHT);
				EntityManager::GetInstance().AddEntity(brick);
			}
		}
		++rowIndex;
	}

	importFile.close();
}
