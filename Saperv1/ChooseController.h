#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
using namespace std;

class ChooseController
{
	vector<string>options;
	vector<int*>optionsExt;
	vector<char>place;
	int choose;
	int oldChoose;
	void getMove();
	void showOptions();
	void setSelect();
	void coutSAPER();
public:
	int* GET_EVENT();
	ChooseController();
	~ChooseController();
};

