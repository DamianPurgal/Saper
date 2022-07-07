#include "stdafx.h"
#include "Bomb.h"



int Bomb::getHeight()
{
	return height;
}

int Bomb::getWidth()
{
	return width;
}

void Bomb::reDraw()
{
	height = rand() % this->mapHeight;
	width = rand() % this->mapWidth;
}

Bomb::Bomb(int mapHeight, int mapWidth)
{
	this->mapHeight = mapHeight;
	this->mapWidth = mapWidth;
	reDraw();
	
}


Bomb::~Bomb()
{
}
