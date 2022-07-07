#pragma once
#include <iostream>
#include <string>
#include "BombController.h"
#include <vector>
#include "Signs.h"
using namespace std;
class MapGenerator
{
	BombController *bombCTR;
	void insertBombs();
public:
	char **map;
	int mapHeight;
	int mapWidth;
	bool isNumber(int height, int width);
	void increaseSquare(int height, int width);
	void showMap();
	MapGenerator(int bombAmount, int mapHeight, int mapWidth, int height, int width);
	~MapGenerator();
};