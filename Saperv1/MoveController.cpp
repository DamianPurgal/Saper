#include "stdafx.h"
#include "MoveController.h"


int * MoveController::GET_EVENT()
{
	int*tab = new int[2];
	unsigned char sign;
	sign = _getch();
	if (sign == 75)
	{
		width--;
		if (width < 0)
			width = 0;
	}
	if (sign == 77)
	{
		width++;
		if (width >= mapWidth)
			width = mapWidth-1;
	}
	if (sign == 72)
	{
		height--;
		if (height < 0)
			height = 0;
	}
	if (sign == 80)
	{
		height++;
		if (height >= mapHeight)
			height = mapHeight-1;
	}
	if (sign == 13)
	{
		tab[0] = -1;
		tab[1] = -1;
		return tab;
	}if (sign == 32)
	{
		tab[0] = -3;
		tab[1] = -3;
		return tab;
	}
	tab[0] = height;
	tab[1] = width;
	return tab;
}

MoveController::MoveController(int height, int width, int mapHeight, int mapWidth)
{
	this->height = height;
	this->width = width;
	this->mapHeight = mapHeight;
	this->mapWidth = mapWidth;
}


MoveController::~MoveController()
{
}
