
#include <iostream>
#include <string>
#include <exception>
#include <iomanip>
#include <fstream>

#include "Operations.h";
using namespace std;

int GetElementConsole();
 
void SaveData(tamagotchi dog, string path);

void DeleteFile(string path);

void LoadData(string path, int& health , int& hunger, int& fatigue, int valueExit);

int main()
{
	int counterFeed=3;
	int counterPlay = 3;
	string path ="log.txt";
	tamagotchi dog;
	dog.health= 10, dog.fatigue =0, dog.hunger=0;
	//DeleteFile(path);
	for (;;)
	{	
		setlocale(LC_ALL, "Rus");
		system("cls");
		cout<< "  здоровье: " << dog.health << "  голод: " << dog.hunger << " усталость: "<< dog.fatigue<<"\n"
			<<"  Меню\n"
			<< "  1 покормить\n"
			<< "  2 сон  \n"
			<< "  3 поиграть\n"
			<< "  4 загрузить параметры последнего питомца\n" 
			<< "  0 выход\n"
			<< "  Выберите пункт меню  ";
		int valueForMenu = GetElementConsole();
		switch (valueForMenu)
		{
		case 1:
		{	
			dog.Feed(dog.health, dog.hunger, dog.fatigue, counterFeed , counterPlay);
			SaveData (dog, path);
			system("pause");
			if (counterFeed == -100)
			{
				return 0;
			}
			break;
		}
		case 2:
		{
			dog.Sleep(dog.health, dog.hunger, dog.fatigue, counterFeed, counterPlay);
			SaveData(dog, path);
			system("pause");
			break;
		}
		case 3:
		{
			dog.Play(dog.health, dog.hunger, dog.fatigue, counterFeed , counterPlay);
			SaveData(dog, path);
			system("pause");
			break;
		}
		case 4:
		{
			LoadData(path, dog.health, dog.hunger, dog.fatigue, 3);
			break;
		}
		case 0:
		{
			cout<<"  хотите сохранить питомца? \n"
			<<"  1 да\n"
			<<"  2 нет\n ";
			int valueExit = GetElementConsole();
			LoadData(path, dog.health, dog.hunger, dog.fatigue, valueExit);
			system("pause");
			return 0;
		}

		default:
		{
			std::cout << "  Неверное значение\n";
			system("pause");
			break;
		}
		}
	}
}

int GetElementConsole()
{
	while (true)
	{
		std::string inputValue;
		getline(cin, inputValue);

		try
		{
			size_t length;
			const int number = stoi(inputValue, &length);
			if (length == inputValue.length())
			{
				return number;
			}
		}
		catch (std::exception& e)
		{
			cout << "  Это не число! Попробуйте еще раз " << endl;
		}
	}
}

void SaveData(tamagotchi dog, string path)
{
	ofstream fout;
	fout.open( "text.txt", fstream::app);
	if (!fout.is_open())
	{
		cout << "ощибка открытия файла";
	}
	else
	{
		fout << "  здоровье: " << dog.health << "  голод: " << dog.hunger << " усталость: " << dog.fatigue << "\n";
	}
	
	fout.close();
}

void LoadData(string path, int& health , int& hunger, int& fatigue,int valueExit)
{
	fstream data1;
	data1.open(path, fstream::in | fstream::out);
	if (!data1.is_open())
	{
		cout << "ощибка открытия файла data.txt";
	}
	else 
	{	
		switch (valueExit)
		{
		
		case 1:
		{
			data1 <<health << " " << hunger << " " << fatigue;
			break;
		}
		case 2:
		{
			return;
		}
		case 3 :
		{
			data1 >> health; data1 >> hunger; data1 >> fatigue;
			break;
		}
		}
	}
	data1.close();
	
}


void DeleteFile(string path)
{
	fstream file;
	file.open(path, ios::out);
	file << "";
	file.close();
}

