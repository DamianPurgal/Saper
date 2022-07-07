#pragma once
#include <iostream>
#include "MapGenerator.h"
#include <vector>
#include <queue>
using namespace std;

class RulesController
{
	MapGenerator *mapCTR;
	vector<int*> points;
	queue<int *> timePoints;
	char**map;
	int clock[2][8];
	void addPoint(int height, int width);
	void addToQueue(int height, int width);
	bool isVisited(int height, int width);
	int**visited;
	bool isEmpty(int height, int width);
public:
	bool isBomb(int height, int width);
	void coutQueue();
	void coutPoints();
	RulesController(MapGenerator* MapCTR);
	~RulesController();
	vector<int*> GET_EVENT(int height, int width);

};

