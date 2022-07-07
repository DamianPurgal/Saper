#pragma once
#include <iostream>
#include <conio.h>
using namespace std;

class MoveController
{
	int height;
	int width;
	int mapHeight;
	int mapWidth;

public:
	int*GET_EVENT();
	MoveController(int height, int width, int mapHeight, int mapWidth);
	~MoveController();
};