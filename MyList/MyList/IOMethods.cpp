#include "IOMethods.h"
#include <fstream>

MyList InputConData()
{
	MyList ml_Output; // ��������� ������ ��� ������ � �����i�
	std::string s_Input; // ������ ��� ���������� ����� �����������
	int i_AddingInt; // ��i��� ��� ������ � ������
	std::cout << "����i�� �������� ������ �������i �� ������i�� Enter\n��� ���������� �����, ����i�� end" << std::endl;
	while (s_Input != "end") // ������� ���i, ���� ���������� �� ����� "end"
	{
		try // ���� ��� �����i��� �������� �����
		{
			std::cin >> s_Input; // ������� ��i� � ������i
			if (s_Input == "end") // ���� ������� "end"
				return ml_Output; // �������� ������ � ������ 
			i_AddingInt = std::stoi(s_Input); // ���������i� ������ � Integer
			ml_Output.addBack(i_AddingInt); // ������ ������� � ������
		}
		catch (std::exception &e) // ������ �������
		{
			std::cout << "����������� ��i�, ������i�� ������\n��� ������ ����i�� \"end\"" << std::endl;
		}
	}
	return ml_Output; // ���i� ������� ������, ���� ���������� �� ��i� ���i
}

MyList InputRand()
{
	MyList ml_Out; // ������ ��� ������ � �����i�
	int i_CountOfNum, // �i���i��� �������i� ������
		i_RandMin, // �i�i������ �������� ������������
		i_RandMax; // ����������� �������� ������������
	try // ���� ��� �����i��� �������� �����
	{
		// ������� ���i
		std::cout << "����i�� �i���i��� ���������� ����� ��� ���������� ������: \n";
		std::cin >> i_CountOfNum;
		std::cout << "����i�� �i�i������ �� ����������� �������� ������������, ����� ����i�:\n";
		std::cin >> i_RandMin >> i_RandMax;
		// ����� ���������� ��������
		for (; i_CountOfNum > 0; i_CountOfNum--)
			ml_Out.addBack(i_RandMin + rand() % i_RandMax);
		return ml_Out; // ��������� ��������� ������
	}
	catch (std::exception &e) // ������ �������
	{
		std::cout << "�������: " << e.what() << std::endl;
	}
	
	return ml_Out; // ��������� ������ ������, ���� �i������� �������
}

MyList ReadFromFileTxt(std::string s_pathToFile)
{
	std::ifstream if_File(s_pathToFile); //�i�������� ���� ��� �������
	if (!if_File) // ���� ���� �� ��������
	{
		std::cout << "��������� �i������ ����!!!" << std::endl;
	}
	else // ���� ���� �i�������
	{
		std::string s_ReadData; // ������ ��� ���������� � �����
		int i_InputData; // ��i��� ��� ������ � ������
		MyList ml_Output; // ������ ��� ���������� � �����i�
		for (int i_Line = 1; if_File; i_Line++) // ��������� ��������� �����, ���� � ���i � ����i
		{
			if_File >> s_ReadData; // ������� ���i � �����
			try // ���� ��� �����i��� �������� �����
			{
				i_InputData = std::stoi(s_ReadData); //���������� string � integer 
			}
			catch (std::exception & e) // ������ �������
			{
				std::cout << "������� ���������� � ����� � ����� " << i_Line << std::endl; // �������� ���i������� ��� ������� ����� � ����� �� ���������� ����������
			}
			ml_Output.addBack(i_InputData); // ������ ���i � ������
		}
		ml_Output.deleteBack(); // ��������� ����i ���i (�������� ����� �����i� ����� ��i�i)
		return ml_Output; // ��������� ������ � �����i�
	}
}

void FillFileTxt(std::string s_pathToFile, MyList ml_inputData)
{
	std::ofstream of_File(s_pathToFile); // �i�������� ���� ��� ������
	if (of_File) //���� ������� �i������ ���� ��� ������
	{
		//�������� ���i � ����
		for (int i = 0; i < ml_inputData.getSize(); i++)
			of_File << ml_inputData.getValue(ml_inputData.getByIndex(i)) << '\n';
		of_File.close(); // ��������� ����
	}
	else // ���� �� ������� �i������, �� �������� ����
	{
		std::cout << "������� ������ �����" << std::endl;
	}
}

MyList ReadFromFileBin(std::string s_pathToFile)
{
	MyList ml_Out; // ������ ��� ������ � �����i�
	ItemList il_Read; // ��������� ��������� �������� ������
	ItemList* p_item = new ItemList; // ��������� ����i���� � ���'��i 
	std::ifstream if_File(s_pathToFile, std::ios::binary); // �i�������� ���� ��� �i������� ����������
	while (if_File.read((char*)&il_Read, sizeof(ItemList))) // ���� � ���i � ���i
	{
		p_item = &il_Read; //���������� ���i � ���������
		ml_Out.addBackStruct(p_item); // ������ ������� ������
	}
	return ml_Out; // ��������� ������ � �����i�
}

void FillFileBin(std::string s_pathToFile, MyList ml_inputData)
{
	ItemList il_OutData; // ���������� ������� ������
	std::ofstream of_File(s_pathToFile, std::ios::binary); //�i�������� ���� ��� ������
	for (int i = 0; i < ml_inputData.getSize(); i++) // ���� � ��i����� ������ � ��������
	{
		il_OutData = *(ml_inputData.getByIndex(i)); // �������� ������� ������ �� i������
		of_File.write((char*)&il_OutData, sizeof(ItemList)); // �������� ���i � ����
	}
	of_File.close(); // ��������� ����
}

void PrintList(MyList ml_inputData, bool b_lineOrColum)
{
	if(b_lineOrColum) // ���i� ������ � ����� ����� �������i�
		for (int i = 0; i < ml_inputData.getSize(); i++)
			std::cout << ml_inputData.getValue(ml_inputData.getByIndex(i)) << '\t';
	else
		for (int i = 0; i < ml_inputData.getSize(); i++) // �i��i� ������ � ��������
			std::cout << ml_inputData.getValue(ml_inputData.getByIndex(i)) << '\n';
}

