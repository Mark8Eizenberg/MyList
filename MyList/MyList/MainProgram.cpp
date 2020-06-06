#include <iostream>
#include <string>
#include "MyList.h"
#include "IOMethods.h"

int main()
{
	using namespace std; // ������� �� �����i� i��� ���������� �i��i����� �++
	setlocale(LC_ALL, "russian"); // �i�������� ��������
	string s_Temp; // ��������� ������ ��� ��������� �����
	int i_Menu; // ����� �� �������� � ����
	bool b_exit = false; // ����� � ����
	MyList l_Test;
	cout << "��������� �����i�" << endl;
	while (!b_exit)
	{
		cout << "\t\t����\n1 - ������� ���i � ���������� �����\n2 - ������� ���i � �i������� �����\n3 - ������ ���i ������\n4 - ������ ��������i ���i\n5 - �������� ���i � ��������� ����\n6 - �������� ���i � �i����� ����\n7 - ���i� � ��������" << endl;
		try
		{
			cin >> s_Temp;
			i_Menu = stoi(s_Temp);
			switch (i_Menu)
			{
			case 1:
				system("cls");
				cout << "����i�� ���� �� �����, ���� ��������i �i����" << endl;
				cin >> s_Temp;
				l_Test = ReadFromFileTxt(s_Temp);
				cout << "���� �������, ���i � �����:" << endl;
				PrintList(l_Test, false);
				break;
			case 2:
				system("cls");
				cout << "����i�� ���� �� �����, ���� ��������i �i����" << endl;
				cin >> s_Temp;
				l_Test = ReadFromFileBin(s_Temp);
				cout << "���� �������, ���i � �����:" << endl;
				PrintList(l_Test, false);
				break;
			case 3:
				system("cls");
				l_Test = InputConData();
				cout << "���� �������, ���i � �����:" << endl;
				PrintList(l_Test, false);
				break;
			case 4:
				system("cls");
				l_Test = InputRand();
				cout << "���� �������, ���i � �����:" << endl;
				PrintList(l_Test, false);
				break;
			case 5:
				system("cls");
				cout << "\t\t�����!\n������ ������� ���� ��������� �� ����� �������\n����i�� ���� �� �����, ���� ��������i �i����" << endl;
				cin >> s_Temp;
				FillFileTxt(s_Temp, l_Test);
				cout << "���� �������� ���i���!" << endl;
				break;
			case 6:
				system("cls");
				cout << "\t\t�����!\n������ ������� ���� ��������� �� ����� �������\n����i�� ���� �� �����, ���� ��������i �i����" << endl;
				cin >> s_Temp;
				FillFileBin(s_Temp, l_Test);
				cout << "���� �������� ���i���!" << endl;
				break;
			case 7:
				b_exit = true;
				break;
			default:
				cout << "���i��� ��������! " << endl;
				break;
			}
		}
		catch (const std::exception&)
		{
			cout << "���i��� ��������! " << endl;
		}
	}
	return 0;
}