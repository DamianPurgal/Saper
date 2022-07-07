#include "stdafx.h"
#include "RulesController.h"


void RulesController::addPoint(int height, int width)
{
	points.push_back(new int[2]);
	points[points.size() - 1][0] = height;
	points[points.size() - 1][1] = width;
}

void RulesController::addToQueue(int height, int width)
{
	cout << height << width<<endl;
	int theight;
	int twidth;
	bool isGood = true;
	for (int i = 0; i < 8; i++)
	{
		theight = height + clock[0][i];
		twidth = width + clock[1][i];
		if (theight >= mapCTR->mapHeight || theight < 0)
			isGood = false;
		if (twidth >= mapCTR->mapWidth || twidth < 0)
			isGood = false;
		if (isGood)
		{
			if (!isVisited(theight, twidth))
			{
				if (isEmpty(theight, twidth))
				{
					timePoints.push(new int[2]{ theight,twidth });
					visited[theight][twidth] = 1;
					addPoint(theight, twidth);
				}
				else if (!isBomb(theight, twidth))
				{
					visited[theight][twidth] = 1;
					addPoint(theight, twidth);
				}
			}
		}
		isGood = true;
	}

}

bool RulesController::isVisited(int height, int width)
{
	if (visited[height][width] == 1)
		return true;
	else
		return false;
}

bool RulesController::isBomb(int height, int width)
{
	if (mapCTR->map[height][width] == BOMB)
		return true;
	else
		return false;
}

bool RulesController::isEmpty(int height, int width)
{
	if (mapCTR->map[height][width] == EMPTY)
		return true;
	else
		return false;
}

void RulesController::coutQueue()
{
	while (!timePoints.empty())
	{
		cout << timePoints.front()[0] << "," << timePoints.front()[1] << endl;
		timePoints.pop();
	}
	
}

void RulesController::coutPoints()
{
	cout << "points:" << endl;
	for (int i = 0; i < points.size(); i++)
	{
		cout << points[i][0] << "," << points[i][1] << endl;
	}
}

RulesController::RulesController(MapGenerator* MapCTR)
{
	this->mapCTR = MapCTR;
	clock[0][0] = -1;
	clock[0][1] = -1;
	clock[0][2] = 0;
	clock[0][3] = 1;
	clock[0][4] = 1;
	clock[0][5] = 1;
	clock[0][6] = 0;
	clock[0][7] = -1;
	clock[1][0] = 0;
	clock[1][1] = 1;
	clock[1][2] = 1;
	clock[1][3] = 1;
	clock[1][4] = 0;
	clock[1][5] = -1;
	clock[1][6] = -1;
	clock[1][7] = -1;

}


RulesController::~RulesController()
{
}

vector<int*> RulesController::GET_EVENT(int height, int width)
{
	points.clear();
	visited = new int*[mapCTR->mapHeight ];
	for (int i = 0; i < mapCTR->mapHeight; i++)
	{
		visited[i] = new int[mapCTR->mapWidth];
		for (int j = 0; j < mapCTR->mapWidth; j++)
		{
			visited[i][j] = 0;
		}
	}
	if (!isVisited(height, width))
	{
		visited[height][width] = 1;
		addPoint(height, width);
	}
	if (mapCTR->map[height][width] == EMPTY)
	{
		addToQueue(height, width);
		while (!timePoints.empty())
		{
			addToQueue(timePoints.front()[0], timePoints.front()[1]);
			timePoints.pop();
		}
	}

	return points;
}
