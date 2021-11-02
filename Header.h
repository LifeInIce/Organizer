#pragma once
#include <iostream>
#include <fstream>
struct List
{
	std::string priority;
	std::string name;
	unsigned int dataM ;
	unsigned int dataD ;
	unsigned int timeH ;
	unsigned int timeM  ;
	std::string description;

	void show() {
		std::cout << "  Priority: " << priority << std::endl;
		std::cout << "  Name: " << name << std::endl;
		std::cout << "  Month: " << dataM << std::endl;
		std::cout << "  Day: " << dataD << std::endl;
		std::cout << "  Hour: " << timeH << std::endl;
		std::cout << "  Minutes: " << timeM << std::endl;
		std::cout << "  Description: " << description << std::endl;
	}
};

void sysShow(List*& obj, int i);
void readFromFile(List*& obj);
void showFile(List*& obj);
void addToFile(List*& obj);
void writeToFile(List*& obj);
void remove(List*& obj);
void edit(List*& obj);
void search(List*& obj);
void showMoth(List*& obj);
void showDay(List*& obj);
void showWeek(List*& obj);
void sortChoice(List*& obj);
void Menu(List*& obj);
void sysSortPriority(List*& obj);
void sysSortMonth(List*& obj);
void sysSortDay(List*& obj);
void sysSortHour(List*& obj);
void sysSortMinutes(List*& obj);