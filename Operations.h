#pragma once
#ifndef Operations_H
#define Operations_H
class tamagotchi 
{
public:

	int health, hunger, fatigue;
	

	int Feed(int& health, int& hunger, int& fatigue , int& counterFeed , int& counterPlay) ;

	void Sleep(int& health, int& hunger, int& fatigue , int& counterFeed , int& counterPlay);

	void Play(int& health, int& hunger, int& fatigue, int& counterFeed, int& counterPlay);
};
#endif
