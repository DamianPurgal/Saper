#pragma once
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

class Bomb
{
	int height;
	int width;
	int mapHeight;
	int mapWidth;
public:
	int getHeight();
	int getWidth();
	void reDraw();
	Bomb(int mapHeight=1, int mapWidth=1);
	~Bomb();
};

