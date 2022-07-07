#include "stdafx.h"
#include "GameController.h"


int * GameController::GET_POINT() // Podawane w (y,x)
{
	int*tab = new int[2];
	tab = viewCTR->GET_EVENT();
	//cout << tab[0] << " " << tab[1]<<endl;
	return tab;
}

void GameController::sendData(vector<int*> dataChange)
{
	char*tabOfChanges = new char[dataChange.size()];
	showedSize += dataChange.size();
	for (int i = 0; i < dataChange.size(); i++)
	{
		tabOfChanges[i] = mapCTR->map[dataChange[i][0]][dataChange[i][1]];
	}
	viewCTR->CHANGES(dataChange, tabOfChanges);
}

void GameController::coutWIN()
{
	cout << endl;
	if (WIN == 0)
	{
		cout << "                    ";
		cout << "     PRZEGRALES!     " << endl;
		//cout << "#####################" << endl;
		//cout << "#                   #" << endl;
		//cout << "#  ###         ###  #" << endl;
		//cout << "#  ###         ###  #" << endl;
		//cout << "#  ###         ###  #" << endl;
		//cout << "#                   #" << endl;
		//cout << "#    ###########    #" << endl;
		//cout << "#   #           #   #" << endl;
		//cout << "#                   #" << endl;
		//cout << "#####################" << endl;
	}
	else
	{
		cout << "                    ";
		cout << "      WYGRALES!     " << endl;
		//cout << "#####################" << endl;
		//cout << "#                   #" << endl;
		//cout << "#  ###         ###  #" << endl;
		//cout << "#  ###         ###  #" << endl;
		//cout << "#  ###         ###  #" << endl;
		//cout << "#                   #" << endl;
		//cout << "#   #           #   #" << endl;
		//cout << "#    ###########    #" << endl;
		//cout << "#                   #" << endl;
		//cout << "#####################" << endl;
	}
}

GameController::GameController()
{
	chooseCTR = new ChooseController();
	int*mapData = chooseCTR->GET_EVENT();
	this->bombAmount = mapData[2];
	this->mapHeight = mapData[0];
	this->mapWidth = mapData[1];
	this->mapSize =mapHeight*mapWidth;
	this->showedSize = 0;
	viewCTR = new ViewController(mapHeight, mapWidth);

	int *point = GET_POINT();
	mapCTR = new MapGenerator(bombAmount, mapHeight, mapWidth, point[0], point[1]);
	rulesCTR = new RulesController(mapCTR);
	for (;;)
	{
		if (!rulesCTR->isBomb(point[0], point[1]))
		{
		
			sendData(rulesCTR->GET_EVENT(point[0], point[1]));
			if (showedSize == mapSize - bombAmount)
			{
				
				WIN = true;
				break;
			}
			point = GET_POINT();
		}
		else
		{
			WIN = false;
			system("cls");
			viewCTR->showMap();
			cout << endl;
			mapCTR->showMap();
			break;
		}
	}
	coutWIN();
}


GameController::~GameController()
{
}