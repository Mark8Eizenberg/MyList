#pragma once
#include <iostream>
#include <string>
#include "MyList.h"

// Функцiя зчитування списку з клавiатури, ввiд користувача
MyList InputConData();

// Функцiя заповнення списку рандомними значеннями
MyList InputRand();

// Функцiя зчитування списку з текстового файлу
MyList ReadFromFileTxt(std::string s_pathToFile);

// Функцiя запису списку в текстовий файл
void FillFileTxt(std::string s_pathToFile, MyList ml_inputData);

// Функцiя зчитування списку з бiнарного файлу
MyList ReadFromFileBin(std::string s_pathToFile);

// Функцiя запису списку в бiнарний файл
void FillFileBin(std::string s_pathToFile, MyList ml_inputData);

// Функцiя виводу списку на екран консолi
void PrintList(MyList ml_inputData, bool b_lineOrColum);
