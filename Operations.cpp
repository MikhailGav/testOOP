#include <iostream>

#include "Operations.h";
using namespace std;



int tamagotchi::Feed(int& health, int& hunger, int& fatigue, int& counterFeed, int& counterPlay)
{
	if (health <= 0)
	{
		cout << "питомец умер, хотите перезапустить? \n"
			<< "1 да \n"
			<<"2 нет \n";
		int valueForMenu ;
		cin>> valueForMenu;
		if (valueForMenu == 1)
		{
			health = 10, fatigue = 0, hunger = 0;
			counterFeed = 3;
		}
		counterFeed =-100;
		return counterFeed;
	}
	if(counterFeed <0)
	{
		cout<<"		вы перекормили, здоровье уменьшено на 1 ед. \n";
	}
	else 
	{
		cout << "	переедание наступит через " << counterFeed << " кормления \n ";
	}

	if (counterFeed <=0)
	{
		health--;
	}
	counterFeed--;
	if (hunger > 0)
	{
		hunger = hunger - 1;
		return 1;
	}

	
	
}

void tamagotchi::Sleep(int& health, int& hunger, int& fatigue, int& counterFeed , int& counterPlay)
{
	if (health <= 0)
	{
		cout << "питомец умер \n";
		return;
	}
	counterFeed = counterPlay =3;
	fatigue = 0;
	if (health < 10 && health>0)
	{
		health++;
	}
	if (hunger <10)
	{
		hunger++;
	}
	
}

void tamagotchi::Play(int& health, int& hunger, int& fatigue, int& counterFeed, int& counterPlay)
{
	counterFeed=3;
	if (counterPlay < 0)
	{
		cout << "		вы переиграли, здоровье уменьшено на 1 ед. \n";
	}
	else
	{
		cout << " 	лимит игр на данный момент  " << counterPlay << "\n";
	}
	if (health <= 0)
	{
		cout << "питомец умер \n";
		return;
	}
	if (counterPlay <= 0)
	{
		health--;
	}
	counterPlay--;
	fatigue ++;
	if (fatigue>10)
	{
		fatigue=10;
	}
}


