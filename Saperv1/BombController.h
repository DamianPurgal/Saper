#pragma once
#include <iostream>
#include "Bomb.h"
using namespace std;

class BombController
{
	int bombAmount;
	int Pwidth;
	int Pheight;
	bool isTheSame(int am);
	bool isPlayerPos(int height, int width);
public:
	Bomb ** bombs;
	BombController(int bombAmount,int height, int width, int Pheight, int Pwidth);
	~BombController();
	int getBombAmount();
	void showBombsPoint();
};
