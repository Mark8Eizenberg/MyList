#include <iostream>
#include <string>
#include "MyList.h"
#include "IOMethods.h"

int main()
{
	using namespace std; // Вказуємо на простiр iмен стандартної бiблiотеки С++
	setlocale(LC_ALL, "russian"); // Пiдключаємо кирилицю
	string s_Temp; // Тимчасова строка для текстових даних
	int i_Menu; // Змінна дя навігації в меню
	bool b_exit = false; // Вихід з меню
	MyList l_Test;
	cout << "Программа спискiв" << endl;
	while (!b_exit)
	{
		cout << "\t\tМеню\n1 - Зчитати данi з текстового файлу\n2 - Зчитати данi з бiнарного файлу\n3 - Ввести данi вручну\n4 - Ввести випадковi данi\n5 - Зберегти данi в текстовий файл\n6 - Зберегти данi в бiнарий файл\n7 - Вихiд з програми" << endl;
		try
		{
			cin >> s_Temp;
			i_Menu = stoi(s_Temp);
			switch (i_Menu)
			{
			case 1:
				system("cls");
				cout << "Введiть шлях до файлу, лише латинськi лiтери" << endl;
				cin >> s_Temp;
				l_Test = ReadFromFileTxt(s_Temp);
				cout << "Файл зчитано, данi з файлу:" << endl;
				PrintList(l_Test, false);
				break;
			case 2:
				system("cls");
				cout << "Введiть шлях до файлу, лише латинськi лiтери" << endl;
				cin >> s_Temp;
				l_Test = ReadFromFileBin(s_Temp);
				cout << "Файл зчитано, данi з файлу:" << endl;
				PrintList(l_Test, false);
				break;
			case 3:
				system("cls");
				l_Test = InputConData();
				cout << "Файл зчитано, данi з файлу:" << endl;
				PrintList(l_Test, false);
				break;
			case 4:
				system("cls");
				l_Test = InputRand();
				cout << "Файл зчитано, данi з файлу:" << endl;
				PrintList(l_Test, false);
				break;
			case 5:
				system("cls");
				cout << "\t\tУВАГА!\nСписок повиний бути створений до цього моменту\nВведiть шлях до файлу, лише латинськi лiтери" << endl;
				cin >> s_Temp;
				FillFileTxt(s_Temp, l_Test);
				cout << "Файл записано успiшно!" << endl;
				break;
			case 6:
				system("cls");
				cout << "\t\tУВАГА!\nСписок повиний бути створений до цього моменту\nВведiть шлях до файлу, лише латинськi лiтери" << endl;
				cin >> s_Temp;
				FillFileBin(s_Temp, l_Test);
				cout << "Файл записано успiшно!" << endl;
				break;
			case 7:
				b_exit = true;
				break;
			default:
				cout << "Невiрне введення! " << endl;
				break;
			}
		}
		catch (const std::exception&)
		{
			cout << "Невiрне введення! " << endl;
		}
	}
	return 0;
}