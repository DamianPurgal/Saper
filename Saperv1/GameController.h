#pragma once
#include <iostream>
#include <string>
#include "ViewController.h"
#include "MapGenerator.h"
#include "RulesController.h"
#include "ChooseController.h"
using namespace std;

class GameController
{
	int mapSize;
	int showedSize;
	ChooseController* chooseCTR;
	ViewController* viewCTR;
	MapGenerator* mapCTR;
	RulesController* rulesCTR;
	vector<int*> dataChange;
	int bombAmount;
	bool WIN;
	int mapHeight;
	int mapWidth;
	int*GET_POINT();
	void sendData(vector<int*> dataChange);
	void coutWIN();
public:
	GameController();
	~GameController();
};