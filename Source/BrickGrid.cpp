#include "BrickGrid.h"
#include "Brick.h"

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
	//temp buffer
	std::string currentLine;

	int lineCount = 0;
	while (std::getline(importFile, currentLine))
	{
		lineCount += 1;

		if (currentLine.size() != MAP_LENGTH)
		{
			std::cout << "Map lenght invalid at line : " << lineCount << std::endl;
			return;
		}
	}

	if (lineCount != MAP_HEIGHT)
	{
		std::cout << "Map heigth invalid" << std::endl;
		return;
	}

	//Getline starts from last line of file
	for (int j = lineCount; j > 0; j--)
	{
		//Line
		for (int i = 0; i < MAP_LENGTH; i++)
		{
			if (currentLine.at(i) == 'o' || currentLine.at(i) == 'O')
				continue;

			auto tempBrick = std::make_shared<Brick>(i,j);
			AddBrick(tempBrick);
		}
	}
}
