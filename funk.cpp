#include "Header.h"
#include <Windows.h>

char fileName[20] = "info.txt"; //название файла в корне проекта
int unsigned counter = 0;

void sysShow(List*& obj, int i) {
	if (i < 9) {
		if (obj[i].priority != "Low")

			std :: cout << i + 1 << ".  " << obj[i].priority << "\t" << obj[i].name << '\t' << obj[i].dataM << '\t' << obj[i].dataD << '\t' << obj[i].timeH << '\t' << obj[i].timeM << "\t  " << obj[i].description << std :: endl;
		else std :: cout << i + 1 << ".  " << obj[i].priority << "\t\t" << obj[i].name << '\t' << obj[i].dataM << '\t' << obj[i].dataD << '\t' << obj[i].timeH << '\t' << obj[i].timeM << "\t  " << obj[i].description << std :: endl;
	}
	else if (i < 99) {
		if (obj[i].priority != "Low")
			std :: cout << i + 1 << ". " << obj[i].priority << "\t" << obj[i].name << '\t' << obj[i].dataM << '\t' << obj[i].dataD << '\t' << obj[i].timeH << '\t' << obj[i].timeM << "\t  " << obj[i].description << std :: endl;
		else std :: cout << i + 1 << ". " << obj[i].priority << "\t\t" << obj[i].name << '\t' << obj[i].dataM << '\t' << obj[i].dataD << '\t' << obj[i].timeH << '\t' << obj[i].timeM << "\t  " << obj[i].description << std :: endl;
	}
	else if (i < 999) {
		if (obj[i].priority != "Low")
			std :: cout << i + 1 << "." << obj[i].priority << "\t" << obj[i].name << '\t' << obj[i].dataM << '\t' << obj[i].dataD << '\t' << obj[i].timeH << '\t' << obj[i].timeM << "\t  " << obj[i].description << std :: endl;
		if (i == 998) std :: cout << "\tThe first 999 cases have been shown\n";
	}
}
void readFromFile(List*& obj) // чтение файла
{
	std :: ifstream file;
	file.open(fileName, std :: ios::in);  // открытие  файла

	if (!file) { // проверка на наличие файла
		std :: cout << "Error! File not Found!\n";
		return;
	}
	std :: string tPriority;
	std :: string tName;
	int tfDataM;
	int tDataD;
	int tTimeH;
	int tTimeM;
	std :: string tDescription;
	counter = 0; // обнуляем глобаьную пременную для счета позиций в файле
	while (file >> tPriority >> tName >> tfDataM >> tDataD >> tTimeH >> tTimeM >> tDescription) { //чтение файла
		List* objT = new List[counter + 1]; // временный динамический массив расширяем
		for (int i = 0; i < counter; i++) {
			objT[i].priority = obj[i].priority;
			objT[i].name = obj[i].name;
			objT[i].dataM = obj[i].dataM;
			objT[i].dataD = obj[i].dataD;
			objT[i].timeH = obj[i].timeH;
			objT[i].timeM = obj[i].timeM;
			objT[i].description = obj[i].description;
		
		}
		objT[counter].name = tName;
		objT[counter].priority = tPriority;
		objT[counter].name = tName;
		objT[counter].dataM = tfDataM;
		objT[counter].dataD = tDataD;
		objT[counter].timeH = tTimeH;
		objT[counter].timeM = tTimeM;
		objT[counter].description = tDescription;
	
		delete[] obj; // удаляем исходный массив
		obj = objT; // перебрасуем указатель с временного
		objT = nullptr; // очищаем временный
		++counter;// счетчик +1
	}
	file.close(); // закрываем файл
}
void showFile(List*& obj) { // показываем что в файле
	system("cls"); // очистка консоли

	std :: cout << "\nShow for Day press 1\nShow for Week press 2\nShow for Month press 3\nShow all list press 4\nFor Exit press 0\n";
	int choice;
	std :: cin >> choice;
	std :: cout << "Your Choice is: " << choice << std :: endl;
	switch (choice)
	{
	case 0:
		Menu(obj);
	break;
	case 1:
		showDay(obj);
		break;
	case 2:
		showWeek(obj);
		break;
	case 3:
		showMoth(obj);
		break;
	case 4:
		readFromFile(obj);
		std :: cout << "N   Priority\tName\tMonth\tDay\tHour\tMinutes\t  Description\n";
		for (int i = 0; i < counter; i++) {
			sysShow(obj, i);
		}
		break;
	default:
		break;
	}
	
	
}
void addToFile(List*& obj) // добавление в файл
{
	std :: ofstream file;
		file.open(fileName, std :: ios::app); // добавление записи в файл
		if (!file.is_open()) { // проверка на открытость файла
		std :: cout << "Error! File is Open!\n";
		return;
		}
	std :: string priority;
		do {
		std :: cout << "\nEnter Priority (High | Middle | Low) :\t";
		std :: cin >> priority;
		if (priority != "H" && priority != "M" && priority != "L" && priority != "h" && priority != "m" && priority != "l" && priority != "High" && priority != "Middle" && priority != "Low" && priority != "high" && priority != "middle" && priority != "low")
			std :: cout << "\nInvalid input. Please try to enter the correct value.\n ";
		else if (priority == "H" || priority == "h") priority = "High";
		else if (priority == "M" || priority == "m") priority = "Middle";
		else if (priority == "L" || priority == "l") priority = "Low";
		} while (priority != "H" && priority != "M" && priority != "L" && priority != "h" && priority != "m" && priority != "l" && priority != "High" && priority != "Middle" && priority != "Low" && priority != "high" && priority != "middle" && priority != "low");
		std :: cout << "Enter Name:\t";
	 std :: string name;
		 std :: cin >> name;		
	 int dataM;
		do {
		 std :: cout << "Enter Month:\t";
		 std :: cin >> dataM;
		} while (dataM < 1 || dataM >12);
	 int dataD;
		 if (dataM == 1 || dataM == 3 || dataM == 5 || dataM == 7 || dataM == 8 || dataM == 10 || dataM == 12)
			 do {
			 std :: cout << "In this month 31 days. Enter y Day:\t";
			 std :: cin >> dataD;
			 } while (dataD < 1 || dataD >31);
		 else if (dataM == 2)
			 do {
			 std :: cout << "In this month 28 days. Enter y Day:\t";
			 std :: cin >> dataD;
			 } while (dataD < 1 || dataD >28);
		 else
		 do {
			 std :: cout << "In this month 30 days. Enter y Day:\t";
			 std :: cin >> dataD;
		 } while (dataD < 1 || dataD >30);
	int timeH;
		 do {
			 std :: cout << "Enter Hours:\t";
			 std :: cin >> timeH;
		 } while (timeH < 0 || timeH >23);
	 int timeM;
		 do {
			 std :: cout << "Enter Minutes:\t";
			 std :: cin >> timeM;
		 } while (timeM < 0 || timeM >59);
	 std :: cout << "Enter Description:\t";
	 std :: string description;
	 std :: cin >> description;
	 file << priority << '\t' << name << '\t' << dataM << '\t' << dataD<< '\t' << timeH << '\t' << timeM << '\t' << description << std :: endl; // запись в файл
	file.close();
	system("pause"); // пауза
	system("cls"); // очистка консоли
	Menu(obj);
}
void writeToFile(List*& obj) {
	std :: ofstream file;
	file.open(fileName, std :: ios::out); // запись изменений
	if (!file.is_open()) {
		std :: cout << "Error! File is not avaliable!\n";
		return;
	}
	for (int i = 0; i < counter; i++) {
		file << obj[i].priority << '\t' << obj[i].name << '\t' << obj[i].dataM << '\t' << obj[i].dataD << '\t' << obj[i].timeH << '\t' << obj[i].timeM << '\t' << obj[i].description << std :: endl;
	}
	file.close();
}
void remove(List*& obj) // удаление из файла
{
	readFromFile(obj);
	showFile(obj);
	int idDel;
	std :: cout << "Enter index of element to delete:\t";
	std :: cin >> idDel;  // сичтываем позицию для удаления
	--idDel;
	List* objT = new List[counter - 1]; // создаем динамический массив на 1 единицу меньше основного
	for (int i = 0; i < idDel; i++) {
		objT[i].priority = obj[i].priority;
		objT[i].name = obj[i].name;
		objT[i].dataM = obj[i].dataM;
		objT[i].dataD = obj[i].dataD;
		objT[i].timeH = obj[i].timeH;
		objT[i].timeM = obj[i].timeM;
		objT[i].description = obj[i].description;
	}
	for (int i = idDel + 1; i < counter; i++) {
		objT[i-1].priority = obj[i].priority;
		objT[i-1].name = obj[i].name;
		objT[i-1].dataM = obj[i].dataM;
		objT[i-1].dataD = obj[i].dataD;
		objT[i-1].timeH = obj[i].timeH;
		objT[i-1].timeM = obj[i].timeM;
		objT[i-1].description = obj[i].description;
	}
	delete[] obj;
	obj = objT;
	objT = nullptr;
	--counter; // уменьшаем запись кол-ва строк
	writeToFile(obj);
	std :: cout << "Element was deleted\n";
		std :: cout << "List was updated\n";
	std :: cout << "Cases left = " << counter << std :: endl;

	system("pause"); // пауза
	system("cls"); // очистка консоли
	Menu(obj);
	
}
void edit(List*& obj) { // изменение
	showFile(obj);
	std :: cout << "What equipment do you want to change? To Exit press 0\n";
	int choice, choice2;
	std :: cin >> choice;
	if (choice==0)Menu(obj);
	else if (choice <1 || choice > counter) {
		system("cls"); // очистка консоли
		std :: cout << "Invalid input.\n\n";
		edit(obj);
	}
	else {
		system("cls"); // очистка консоли
		obj[choice - 1].show();
		std :: cout << "\n What parameter do you want to change ? \n";
		do {
			std :: cout << "\tPriority press 1\n\tName press 2\n\tMonth press 3\n\tDay press 4\n\tHour press 5\n\tMinutes press 6\n\tDescription press 7\n\tExit press 0\n Your choice - ";
			std :: cin >> choice2;
			switch (choice2)
			{
			case (0):
				break;
			case (1): 
			{
					do {
						std :: cout << "\nEnter obj[choice - 1].priority (High | Middle | Low) :\t";
						std :: cin >> obj[choice - 1].priority;
						if (obj[choice - 1].priority != "H" && obj[choice - 1].priority != "M" && obj[choice - 1].priority != "L" && obj[choice - 1].priority != "h" && obj[choice - 1].priority != "m" && obj[choice - 1].priority != "l" && obj[choice - 1].priority != "High" && obj[choice - 1].priority != "Middle" && obj[choice - 1].priority != "Low" && obj[choice - 1].priority != "high" && obj[choice - 1].priority != "middle" && obj[choice - 1].priority != "low")
							std :: cout << "\nInvalid input. Please try to enter the correct value.\n ";
						else if (obj[choice - 1].priority == "H" || obj[choice - 1].priority == "h") obj[choice - 1].priority = "High";
						else if (obj[choice - 1].priority == "M" || obj[choice - 1].priority == "m") obj[choice - 1].priority = "Middle";
						else if (obj[choice - 1].priority == "L" || obj[choice - 1].priority == "l") obj[choice - 1].priority = "Low";
					} while (obj[choice - 1].priority != "H" && obj[choice - 1].priority != "M" && obj[choice - 1].priority != "L" && obj[choice - 1].priority != "h" && obj[choice - 1].priority != "m" && obj[choice - 1].priority != "l" && obj[choice - 1].priority != "High" && obj[choice - 1].priority != "Middle" && obj[choice - 1].priority != "Low" && obj[choice - 1].priority != "high" && obj[choice - 1].priority != "middle" && obj[choice - 1].priority != "low");
			}
				break;
			case (2):
			{
				std :: cout << "Enter new name:\t";
				std :: cin >> obj[choice - 1].name; }
				break;
			case (3):
				do {
					std :: cout << "Enter Month:\t";
					std :: cin >> obj[choice - 1].dataM;
				} while (obj[choice - 1].dataM < 1 || obj[choice - 1].dataM >12);
				break;
			case (4):
				if (obj[choice - 1].dataM == 1 || obj[choice - 1].dataM == 3 || obj[choice - 1].dataM == 5 || obj[choice - 1].dataM == 7 || obj[choice - 1].dataM == 8 || obj[choice - 1].dataM == 10 || obj[choice - 1].dataM == 12)
					do {
						std :: cout << "In this month 31 days. Enter y Day:\t";
						std :: cin >> obj[choice - 1].dataD;
					} while (obj[choice - 1].dataD < 1 || obj[choice - 1].dataD >31);
				else if (obj[choice - 1].dataM == 2)
					do {
						std :: cout << "In this month 28 days. Enter y Day:\t";
						std :: cin >> obj[choice - 1].dataD;
					} while (obj[choice - 1].dataD < 1 || obj[choice - 1].dataD >28);
				else
					do {
						std :: cout << "In this month 30 days. Enter y Day:\t";
						std :: cin >> obj[choice - 1].dataD;
					} while (obj[choice - 1].dataD < 1 || obj[choice - 1].dataD >30);
				break;
			case (5):
				do {
					std :: cout << "Enter Hours:\t";
					std :: cin >> obj[choice - 1].timeH;
				} while (obj[choice - 1].timeH < 0 || obj[choice - 1].timeH >23);
				break;
			case (6):
				do {
					std :: cout << "Enter Minutes:\t";
					std :: cin >> obj[choice - 1].timeM;
				} while (obj[choice - 1].timeM < 0 || obj[choice - 1].timeM >59);
				break;
			case (7):
				std :: cout << "Enter new Description: \t";
				std :: cin >> obj[choice - 1].description;
				break;
			default:
				system("cls"); // очистка консоли
				obj[choice - 1].show();
				std :: cout << "\nInvalid input. Please try to enter the correct value.\n ";
				break;
			}
		} while (choice2< 0 || choice2 > 7);
		writeToFile(obj);
		system("pause"); // пауза
		system("cls"); // очистка консоли
		Menu(obj);
	}
}
void search(List*& obj) // поиск по файлу
{
	readFromFile(obj);	
	int choice;	
	do {
		std :: cout << "To search by Priority \t\tpress 1.\nTo search by Name, \t\tpress 2.\nTo search by Description, \tpress 3.\nTo search by Date,\t\tpress 4. \nTo search by Date & Time, \tpress 5.\nExit, \t\t\t\tPress 0.\n";
		std :: cin >> choice;
		switch (choice)
		{
		case 0:
			break;
		case 1:
		{
			std :: string fPriority;
			do {
				std :: cout << "\nEnter Priority (High | Middle | Low) :\t";
				std :: cin >> fPriority;
				if (fPriority != "H" && fPriority != "M" && fPriority != "L" && fPriority != "h" && fPriority != "m" && fPriority != "l" && fPriority != "High" && fPriority != "Middle" && fPriority != "Low" && fPriority != "high" && fPriority != "middle" && fPriority != "low")
					std :: cout << "\nInvalid input. Please try to enter the correct value.\n ";
				else if (fPriority == "H" || fPriority == "h") fPriority = "High";
				else if (fPriority == "M" || fPriority == "m") fPriority = "Middle";
				else if (fPriority == "L" || fPriority == "l") fPriority = "Low";
			} while (fPriority != "H" && fPriority != "M" && fPriority != "L" && fPriority != "h" && fPriority != "m" && fPriority != "l" && fPriority != "High" && fPriority != "Middle" && fPriority != "Low" && fPriority != "high" && fPriority != "middle" && fPriority != "low");
			std :: cout << "N   Priority\tName\tMonth\tDay\tHour\tMinutes\t  Description\n";
			for (int i = 0; i < counter; i++) {
				if (obj[i].priority == fPriority) {
					sysShow(obj, i);
				}
			}
		}
		break;
		case 2:
		{
			std :: cout << "Enter name: ";
			std :: string fName;
			std :: cin >> fName;
			std :: cout << "N   Priority\tName\tMonth\tDay\tHour\tMinutes\t  Description\n";
			for (int i = 0; i < counter; i++) {
				if (obj[i].name == fName) {
					sysShow(obj, i);
				}
			}

		}break;
		case 3:
		{
			std :: cout << "Enter Description: ";
			std :: string fDescription;
			std :: cin >> fDescription;
			std :: cout << "N   Priority\tName\tMonth\tDay\tHour\tMinutes\t  Description\n";
			for (int i = 0; i < counter; i++) {
				if (obj[i].description == fDescription) {
					sysShow(obj, i);
				}
			}
		}
		break;
		case 4:
		{
			std :: cout << "Enter Moth: ";
			int fDataM;
			std :: cin >> fDataM;
			std :: cout << "Enter Day: ";
			int fDataD;
			std :: cin >> fDataD;
			std :: cout << "\nYour choice :" << fDataM << "." << fDataD << std :: endl;
			std :: cout << "N   Priority\tName\tMonth\tDay\tHour\tMinutes\t  Description\n";
			for (int i = 0; i < counter; i++) {
				if (obj[i].dataM == fDataM && obj[i].dataD == fDataD) {
					sysShow(obj, i);
				}
			}
		}
		break;
		case 5:
		{
			std :: cout << "Enter Moth: ";
			int fDataM;
			std :: cin >> fDataM;
			std :: cout << "Enter Day: ";
			int fDataD;
			std :: cin >> fDataD;
			std :: cout << "Enter Hour: ";
			int fTimeH;
			std :: cin >> fTimeH;
			std :: cout << "\nYour choice :" << fDataM << "." << fDataD << " Within " << fTimeH << " h"  << std :: endl;
			std :: cout << "N   Priority\tName\tMonth\tDay\tHour\tMinutes\t  Description\n";
			for (int i = 0; i < counter; i++) {
				if (obj[i].dataM == fDataM && obj[i].dataD == fDataD && obj[i].timeH == fTimeH) {
					sysShow(obj, i);
				}
			}
		}
		break;
		default:
			system("cls");
			std :: cout << "Invalid input. Please try to enter the correct value.\n";
			
			break;
		}
	} while (choice < 0 || choice > 5);
	system("pause"); // пауза
	system("cls"); // очистка консоли
	Menu(obj);
	}
void showMoth(List*& obj) {
	readFromFile(obj);
	std :: cout << "Enter Moth: ";
	int fDataM;
	std :: cin >> fDataM;
	sortChoice(obj);
	std :: cout << "N   Priority\tName\tMonth\tDay\tHour\tMinutes\t  Description\n";
	for (int i = 0; i < counter; i++) {
		if (obj[i].dataM == fDataM) {			
			sysShow(obj, i);
		}
	}
}
void showDay(List*& obj) {
	readFromFile(obj);
	std :: cout << "Enter Moth: ";
	int fDataM;
	std :: cin >> fDataM;
	std :: cout << "Enter Day: ";
	int fDataD;
	std :: cin >> fDataD;
	sortChoice(obj);
	std :: cout << "N   Priority\tName\tMonth\tDay\tHour\tMinutes\t  Description\n";
	for (int i = 0; i < counter; i++) {
		if (obj[i].dataM == fDataM && obj[i].dataD == fDataD) {
			sysShow(obj, i);
		}
	}

}
void showWeek(List*& obj) {
	readFromFile(obj);
	int temp = 0;
	std :: cout << "Enter Moth: ";
	int fDataM;
	std :: cin >> fDataM;
	std :: cout << "Enter Day: ";
	int fDataD;
	std :: cin >> fDataD;
	std :: cout << "\nYour choice :" << fDataM << "." << fDataD << std :: endl;
	sortChoice(obj);
	std :: cout << "N   Priority\tName\tMonth\tDay\tHour\tMinutes\t  Description\n";
	if (fDataM == 1 || fDataM == 3 || fDataM == 5 || fDataM == 7 || fDataM == 8 || fDataM == 10 || fDataM == 12)  
	{
		for (int i = 0; i < counter; i++) for (int j = 0; j < 7; j++) if (obj[i].dataM == fDataM && obj[i].dataD == fDataD + j) sysShow(obj, i);
		for (int i = 0; i < counter; i++) for (int k = 0; k < (fDataD + 7 - 31); k++) if (fDataD + 7 > 31)  if (obj[i].dataM == (fDataM + 1) && obj[i].dataD == k) sysShow(obj, i);
	}
	else if (fDataM == 2 || fDataM == 4 || fDataM == 6 || fDataM == 9 || fDataM == 11)
	{
		for (int i = 0; i < counter; i++) for (int j = 0; j < 7; j++) if (obj[i].dataM == fDataM && obj[i].dataD == fDataD + j) sysShow(obj, i);
		for (int i = 0; i < counter; i++) for (int k = 0; k < (fDataD + 7 - 30); k++) if (fDataD + 7 > 30)  if (obj[i].dataM == (fDataM + 1) && obj[i].dataD == k) sysShow(obj, i);
	}
	else 
	{
		for (int i = 0; i < counter; i++) for (int j = 0; j < 7; j++) if (obj[i].dataM == fDataM && obj[i].dataD == fDataD + j) sysShow(obj, i);
		for (int i = 0; i < counter; i++) for (int k = 0; k < (fDataD + 7 - 28); k++) if (fDataD + 7 > 28)  if (obj[i].dataM == (fDataM + 1) && obj[i].dataD == k) sysShow(obj, i);
	}
	system("pause"); // пауза
	system("cls"); // очистка консоли
	Menu(obj);
}
void sortChoice(List*& obj) 
{ // сортируем массив (без изменения файла)
	readFromFile(obj);
	std :: cout << "Sort by priority press 1\nSorted by Date and Time press 2\n";
	int choice;
	std :: cin >> choice;
	if (choice == 1) {
		sysSortPriority(obj);	
		sysSortMonth(obj);
		sysSortDay(obj);
		sysSortHour(obj);
		sysSortMinutes(obj);
	}
	else if (choice == 2) {
		sysSortMonth(obj);
		sysSortDay(obj);
		sysSortHour(obj);
		sysSortMinutes(obj);
	}	
	else {
		std :: cout << "Invalid input. Please try to enter the correct value.\n\n";
		sortChoice(obj);
	}
}
void sysSortPriority(List*& obj) {
	for (int i = 0; i < counter; i++) {
		for (int j = 0; j < counter - 1; j++)
		{
			if (obj[j].priority > obj[j + 1].priority)
			{
				List st = obj[j];
				obj[j] = obj[j + 1];
				obj[j + 1] = st;
			}
		}
	}
}
void sysSortMonth(List*& obj) {
	for (int i = 0; i < counter; i++) {
		for (int j = 0; j < counter - 1; j++)
		{
			if (obj[j].priority == obj[j + 1].priority)
			if (obj[j].dataM > obj[j + 1].dataM)
			{
				List st = obj[j];
				obj[j] = obj[j + 1];
				obj[j + 1] = st;
			}
		}
	}
}
void sysSortDay(List*& obj) {
	for (int i = 0; i < counter; i++) {
		for (int j = 0; j < counter - 1; j++)
		{
			if (obj[j].dataM == obj[j + 1].dataM)
				if (obj[j].dataD > obj[j + 1].dataD)
			{
				List st = obj[j];
				obj[j] = obj[j + 1];
				obj[j + 1] = st;
			}
		}
	}
}
void sysSortHour(List*& obj) {
	for (int i = 0; i < counter; i++) {
		for (int j = 0; j < counter - 1; j++)
		{
			if(obj[j].dataD == obj[j + 1].dataD)
				if (obj[j].timeH > obj[j + 1].timeH)
			{
				List st = obj[j];
				obj[j] = obj[j + 1];
				obj[j + 1] = st;
			}
		}
	}
}
void sysSortMinutes(List*& obj) {
	for (int i = 0; i < counter; i++) {
		for (int j = 0; j < counter - 1; j++)
		{
			if (obj[j].dataD == obj[j + 1].dataD)
				if (obj[j].timeH == obj[j + 1].timeH)
					if (obj[j].timeM > obj[j + 1].timeM)
			{
				List st = obj[j];
				obj[j] = obj[j + 1];
				obj[j + 1] = st;
			}
		}
	}
}
void Menu(List*& obj) {
	std :: ifstream file;
	file.open(fileName, std :: ios::in);  // открытие  файла
		if (!file) { // проверка на наличие файла
		std :: ofstream file;
		file.open(fileName, std :: ios::out);
	}
	system("cls");
	std::cout << "\t\tMenu:\n";
	std :: cout << "To display the list, \t\tpress 1\nTo add to the list, \t\tpress 2\nTo remove from the list, \tpress 3\n";
	std :: cout << "To edit the list, \t\tpress 4\nTo search the list \t\tpress 5\nTo exit \t\t\tpress 0\n";
	char ch;
	std :: cin >> ch;
	switch (ch)
	{
	case '0':
		std :: cout << " Thank you for the attention. Bye";
		break;
	case '1':
		system("cls");
		showFile(obj); 
		system("pause"); // пауза
		system("cls"); // очистка консоли
		Menu(obj);
		break;
	case '2':
		system("cls");
		addToFile(obj);
		break;
	case '3':
		system("cls");
		remove(obj);
		break;
	case '4':
		system("cls");
		edit(obj);
		break;
	case '5':
		system("cls");
		search(obj);
		break;
	default:
		std :: cout << "Invalid input. Please try to enter the correct value.\n\n";
		Sleep(1000);
		system("cls");
		Menu(obj);
		break;
	}
}