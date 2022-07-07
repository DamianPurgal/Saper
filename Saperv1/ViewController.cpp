#include "stdafx.h"
#include "ViewController.h"
using namespace std;

void ViewController::showMap()
{
	system("cls");

	coutSAPER();
	coutBorder(1);
	for (int i = 0; i < this->height; i++)
	{
		cout.width(20);
		cout << char(BORDER)<<' ';
		for (int j = 0; j < this->width; j++)
		{

			cout << " ";
			if (i == colored.height && j == colored.width)
			{
				SetConsoleTextAttribute(hOut, 2);
				cout << map[i][j];
				SetConsoleTextAttribute(hOut, 7);
			}
			else if (isFlag(i, j))
			{
				SetConsoleTextAttribute(hOut, 5);
				cout << map[i][j];
				SetConsoleTextAttribute(hOut, 7);
			}
			else
				cout << map[i][j];
		}
		cout << "  "<< char(BORDER);
		cout << endl;
	}
	coutBorder(0);
}

void ViewController::setColoredPoint(int height, int width)
{
	colored.height = height;
	colored.width = width;
}

void ViewController::showFlags()
{
	for (int i = 0; i < flags.size(); i++)
	{
		cout << flags[i][0] << "," << flags[i][1] << endl;
	}
	_getch();
}

void ViewController::addFlag(int height, int width)
{
	if (!isFlag(height, width) && map[height][width]== HIDE )
	{
		if (emptyFlags > 0)
		{
			for (int i = 0; i < flags.size(); i++)
			{
				if (flags[i][0] == -1)
				{
					flags[i][0] = height;
					flags[i][1] = width;
					this->emptyFlags--;
					return;
				}
			}
		}
		else
		{
			flags.push_back(new int[2]);
			flags[flags.size() - 1][0] = colored.height;
			flags[flags.size() - 1][1] = colored.width;
		}
	}
	else
	{
		for (int i = 0; i < flags.size(); i++)
		{
			if (flags[i][0] == height)
			{
				if (flags[i][1] == width)
				{
					flags[i][0] = -1;
					flags[i][1] = -1;
					this->emptyFlags++;
					break;
				}
			}
		}
	}
}

void ViewController::coutBorder(int s)
{
	
	for (int i = 0; i < 2; i++)
	{
		if (i == s)
		{
			cout.width(20);
			cout << char(BORDER);
			for (int j = 0; j < (this->width) * 2 + 3; j++)
			{
				cout << ' ';
			}
			cout << char(BORDER);
			cout << endl;
		}
		else
		{
			cout.width(20);
			for (int j = 0; j < (this->width) * 2 + 5; j++)
			{
				cout << char(BORDER);
			}
			cout << endl;
		}
		
	}
	
}

void ViewController::coutSAPER()
{
	cout << endl;
	coutSpace();
	cout << "           _/_/_/    _/_/    _/_/_/    _/_/_/_/  _/_/_/    " << endl;
	coutSpace();
	cout << "        _/        _/    _/  _/    _/  _/        _/    _/   " << endl;
	coutSpace();
	cout << "         _/_/    _/_/_/_/  _/_/_/    _/_/_/    _/_/_/      " << endl;
	coutSpace();
	cout << "            _/  _/    _/  _/        _/        _/    _/     " << endl;
	coutSpace();
	cout << "     _/_/_/    _/    _/  _/        _/_/_/_/  _/    _/      " << endl;
	cout << endl;
}

void ViewController::coutSpace()
{
	for (int i = 0; i < width / 2; i++)
		cout << " ";
}

bool ViewController::isFlag(int height, int width)
{
	for (int i = 0; i < flags.size(); i++)
	{
		if (flags[i][0] == height)
		{
			if (flags[i][1] == width)
			{
				return true;
			}
		}
	}
	return false;
}

void ViewController::CHANGES(vector<int*>tab, char * tab2)
{
	for (int i = 0; i < tab.size(); i++)
	{
		map[tab[i][0]][tab[i][1]] = tab2[i];
		if (isFlag(tab[i][0], tab[i][1]))
		{
			for (int j = 0; j < flags.size();j++)
			{
				if (flags[j][0] == tab[i][0])
				{
					if (flags[j][1] == tab[i][1])
					{
						flags[j][0] = -1;
						flags[j][1] = -1;
						this->emptyFlags++;
						break;
					}
				}
			}
			
		}
	}
	showMap();
}

int * ViewController::GET_EVENT()
{
	int *tab;
	for (;;)
	{
		tab = moveCTR->GET_EVENT();
		if (tab[0] == -1 || tab[1] == -1)
		{
			tab[0] = colored.height;
			tab[1] = colored.width;
			break;
		}
		if (tab[0] == -3 || tab[1] == -3)
		{
			addFlag(colored.height, colored.width);
		}
		else
		{
			colored.height = tab[0];
			colored.width = tab[1];
		}

		showMap();
	}
	return tab;
}

ViewController::ViewController(int height, int width)
{
	
	this->emptyFlags = 0;
	this->height = height;
	this->width = width;
	this->map = new char*[height];
	for (int i = 0; i < this->height; i++)
	{
		this->map[i] = new char[width];

		for (int j = 0; j < this->width; j++)
		{
			map[i][j] = HIDE;
		}
	}
	colored.height = 1;
	colored.width = 1;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	showMap();
	moveCTR = new MoveController(colored.height, colored.width, height, width);
}


ViewController::~ViewController()
{
}