#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include "MoveController.h"
#include "Signs.h"
using namespace std;

class ViewController
{
	vector<int*> flags;
	MoveController* moveCTR;
	int height;
	int width;
	char ** map;
	int emptyFlags;
	void showFlags();//robocza do zobaczenia pozycji flag
	struct Point
	{
		int height;
		int width;
	};
	HANDLE hOut;
	Point colored;
	void addFlag(int height, int width);
	void coutBorder(int s);
	void coutSAPER();
	void coutSpace();
public:
	bool isFlag(int height, int width);
	void CHANGES(vector<int*>tab, char * tab2);
	int*GET_EVENT();
	ViewController(int height, int width);
	~ViewController();
	void showMap();
	void setColoredPoint(int height, int width);
};