#pragma once
#include <iostream>
#include <string>
#include "MyList.h"

// �����i� ���������� ������ � ����i�����, ��i� �����������
MyList InputConData();

// �����i� ���������� ������ ���������� ����������
MyList InputRand();

// �����i� ���������� ������ � ���������� �����
MyList ReadFromFileTxt(std::string s_pathToFile);

// �����i� ������ ������ � ��������� ����
void FillFileTxt(std::string s_pathToFile, MyList ml_inputData);

// �����i� ���������� ������ � �i������� �����
MyList ReadFromFileBin(std::string s_pathToFile);

// �����i� ������ ������ � �i������ ����
void FillFileBin(std::string s_pathToFile, MyList ml_inputData);

// �����i� ������ ������ �� ����� ������i
void PrintList(MyList ml_inputData, bool b_lineOrColum);
