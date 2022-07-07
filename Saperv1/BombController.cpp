#include "stdafx.h"
#include "BombController.h"
#include <windows.h>

bool BombController::isTheSame(int am)
{
	for (int i = 0; i < am; i++)
	{
		if (bombs[i]->getHeight() == bombs[am]->getHeight())
		{
			if (bombs[i]->getWidth() == bombs[am]->getWidth())
			{
				return true;
			}
		}
	}
	return false;
}

bool BombController::isPlayerPos(int height, int width)
{
	if (height == Pheight && width == Pwidth)
	{
		Sleep(1000);
		return true;
	}
	else return false;
}

void BombController::showBombsPoint()
{
	for (int i = 0; i < this->bombAmount; i++)
	{
		cout << bombs[i]->getHeight() << "," << bombs[i]->getWidth() << endl;
	}
}
BombController::BombController(int bombAmount, int height, int width, int Pheight, int Pwidth)
{
	this->Pheight = Pheight;
	this->Pwidth = Pwidth;
	srand(time(NULL));
	this->bombAmount = bombAmount;
	this->bombs = new Bomb*[bombAmount];
	for (int i = 0; i < bombAmount; i++)
	{
		bombs[i] = new Bomb(height, width);
		if (isTheSame(i) || isPlayerPos(bombs[i]->getHeight(), bombs[i]->getWidth()))
		{
			for (;;)
			{
				bombs[i]->reDraw();
				if (!isTheSame(i) && !isPlayerPos(bombs[i]->getHeight(), bombs[i]->getWidth()))
					break;
			}
		}
	}
}


BombController::~BombController()
{
}

int BombController::getBombAmount()
{
	return this->bombAmount;
}