#include "stdafx.h"
#include "ChooseController.h"


int * ChooseController::GET_EVENT()
{
	coutSAPER();
	showOptions();
	int*answer = new int[3];
	for (;;)
	{
		getMove();
		if (choose == -1)
		{
			answer[0] = optionsExt[oldChoose][0];
			answer[1] = optionsExt[oldChoose][1];
			answer[2] = optionsExt[oldChoose][2];
			return answer;
		}
		else
		{
			system("cls");
			setSelect();
			coutSAPER();
			showOptions();
		}
	}
}

void ChooseController::getMove()
{
	char Csign = _getch();
	int sign = Csign;
	oldChoose = choose;
	place[choose] = ' ';
	if (sign == 80 && choose<options.size()-1)
	{
		choose++;
	}
	if (sign == 72 && choose>0)
	{
		choose--;
	}
	if (sign == 13)
	{
		choose = -1;
	}
}

void ChooseController::showOptions()
{
	for (int i=0;i<options.size();i++)
	{
		cout.width(22);
		cout << place[i] << " " << options[i] << endl;
	}
}

void ChooseController::setSelect()
{
	place[choose] = '>';
}

void ChooseController::coutSAPER()
{
	cout << endl;
	cout.width(20);
	cout << "           _/_/_/    _/_/    _/_/_/    _/_/_/_/  _/_/_/    " << endl;
	cout.width(20);
	cout << "        _/        _/    _/  _/    _/  _/        _/    _/   " << endl;
	cout.width(20);
	cout << "         _/_/    _/_/_/_/  _/_/_/    _/_/_/    _/_/_/      " << endl;
	cout.width(20);
	cout << "            _/  _/    _/  _/        _/        _/    _/     " << endl;
	cout.width(20);
	cout << "     _/_/_/    _/    _/  _/        _/_/_/_/  _/    _/      " << endl;
	cout << endl<<endl;

}

ChooseController::ChooseController()
{
	oldChoose = 0;
	choose = 0;
	options.push_back("Poczatkujacy");
	optionsExt.push_back(new int[3]{ 8,8,10 });
	place.push_back('>');
	options.push_back("Zaawansowany");
	optionsExt.push_back(new int[3]{ 16,16,40 });
	place.push_back(' ');
	options.push_back("Ekspert");
	optionsExt.push_back(new int[3]{ 16,30,99 });
	place.push_back(' ');
}


ChooseController::~ChooseController()
{
}

