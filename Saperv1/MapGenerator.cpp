#include "stdafx.h"
#include "MapGenerator.h"


void MapGenerator::insertBombs()
{
	int bA = bombCTR->getBombAmount();
	for (int i = 0; i < bA; i++)
	{
		increaseSquare(bombCTR->bombs[i]->getHeight(), bombCTR->bombs[i]->getWidth());
	}
}

bool MapGenerator::isNumber(int height, int width)
{
	int sign = map[height][width];
	if (sign > 47 && sign < 58)
		return true;
	else
		return false;
}

void MapGenerator::increaseSquare(int height, int width)
{
	int sign;
	int aheight;
	int awidth;
	for (int i = -1; i < 2; i++)
	{
		aheight = height + i;
		if (aheight < 0)
		{
			aheight++;
			i++;
		}
		if (aheight >= mapHeight)
			break;
		for (int j = -1; j < 2; j++)
		{
			awidth = width + j;
			if (awidth < 0)
			{
				awidth++;
				j++;
			}
			if (awidth >= mapWidth)
				break;

			sign = map[aheight][awidth];
			if (aheight != height || awidth != width)
			{
				if (isNumber(aheight, awidth))
				{
					sign++;
					map[aheight][awidth] = sign;
				}
				else if (map[aheight][awidth] != BOMB)
				{
					map[aheight][awidth] = '1';
				}
			}
		}
	}
	map[height][width] = BOMB;
}

void MapGenerator::showMap()
{
	for (int i = 0; i < mapHeight; i++)
	{
		cout.width(22);
		for (int j = 0; j < mapWidth; j++)
		{
			
			cout << ' ' << map[i][j];
		}
		cout << endl;
	}
}

MapGenerator::MapGenerator(int bombAmount, int mapHeight, int mapWidth, int height, int width)
{
	this->mapHeight = mapHeight;
	this->mapWidth = mapWidth;
	bombCTR = new BombController(bombAmount, mapHeight, mapWidth, height, width);
	map = new char*[mapHeight];
	for (int i = 0; i < mapHeight; i++)
	{
		map[i] = new char[mapWidth];
		for (int j = 0; j < mapWidth; j++)
		{
			map[i][j] = EMPTY;
		}
	}
	insertBombs();
}


MapGenerator::~MapGenerator()
{
}
