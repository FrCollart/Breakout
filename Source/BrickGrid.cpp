#include "BrickGrid.h"

#include <sstream>

#include "Brick.h"
#include "GameConsts.h"

void BrickGrid::AddBrick(std::shared_ptr<class Brick> brick)
{
	m_Bricks.emplace_back(brick);
}

void BrickGrid::RemoveBrick(std::shared_ptr<class Brick> brick)
{
	m_Bricks.erase(std::remove(m_Bricks.begin(), m_Bricks.end(), brick), m_Bricks.end());
}

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
				int x = colIndex * (BRICK_WIDTH + GRID_INTER);
				int y = rowIndex * (BRICK_HEIGHT + GRID_INTER);

				std::cout << "Brick at: x=" << x << ", y=" << y
					<< ", width=" << BRICK_WIDTH << ", height=" << BRICK_HEIGHT << std::endl;

				auto brick = std::make_shared<Brick>(x, y, BRICK_WIDTH, BRICK_HEIGHT);
				AddBrick(brick);
			}
		}
		++rowIndex;
	}

	importFile.close();

}
