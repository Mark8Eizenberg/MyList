#include "IOMethods.h"
#include <fstream>

MyList InputConData()
{
	MyList ml_Output; // Створюємо список для виводу з функцiї
	std::string s_Input; // Строка для зчитування вводу користувача
	int i_AddingInt; // Змiнна для запису в список
	std::cout << "Введiть значення списку поодинцi та натиснiть Enter\nДля завершення вводу, введiть end" << std::endl;
	while (s_Input != "end") // Зчитуємо данi, поки користувач не введе "end"
	{
		try // Блок для перевiрки введених даних
		{
			std::cin >> s_Input; // Зчитуємо ввiд з консолi
			if (s_Input == "end") // Якщо введено "end"
				return ml_Output; // Виводимо список з даними 
			i_AddingInt = std::stoi(s_Input); // Конвертацiя строки в Integer
			ml_Output.addBack(i_AddingInt); // Додаємо елемент у список
		}
		catch (std::exception &e) // Ловимо помилку
		{
			std::cout << "Некоректний ввiд, повторiть спробу\nДля виходу введiть \"end\"" << std::endl;
		}
	}
	return ml_Output; // Вивiд пустого списку, якщо користувач не ввiв данi
}

MyList InputRand()
{
	MyList ml_Out; // Список для виводу з функцiї
	int i_CountOfNum, // Кiлькiсть елементiв списку
		i_RandMin, // Мiнiмальне значення рандомайзеру
		i_RandMax; // Максимальне значення рандомайзеру
	try // Блок для перевiрки введених даних
	{
		// Зчитуємо данi
		std::cout << "Введiть кiлькiсть випадкових чисел для заповнення списку: \n";
		std::cin >> i_CountOfNum;
		std::cout << "Введiть мiнiмальне та максимальне значення рандомайзеру, через пробiл:\n";
		std::cin >> i_RandMin >> i_RandMax;
		// Запис випадкових значеннь
		for (; i_CountOfNum > 0; i_CountOfNum--)
			ml_Out.addBack(i_RandMin + rand() % i_RandMax);
		return ml_Out; // Повертаємо створений список
	}
	catch (std::exception &e) // Ловимо помилку
	{
		std::cout << "Помилка: " << e.what() << std::endl;
	}
	
	return ml_Out; // Повертаємо пустий список, якщо вiдбулась помилка
}

MyList ReadFromFileTxt(std::string s_pathToFile)
{
	std::ifstream if_File(s_pathToFile); //Вiдкриваємо файл для читання
	if (!if_File) // Якщо файл не знайдено
	{
		std::cout << "Неможливо вiдкрити файл!!!" << std::endl;
	}
	else // Якщо файл вiдкрився
	{
		std::string s_ReadData; // Строка для зчитування з файлу
		int i_InputData; // Змiнна для запису в список
		MyList ml_Output; // Список для повернення з функцiї
		for (int i_Line = 1; if_File; i_Line++) // Позначаємо зчитанний рядок, поки є данi в файлi
		{
			if_File >> s_ReadData; // Зчитуємо данi з файлу
			try // Блок для перевiрки введених даних
			{
				i_InputData = std::stoi(s_ReadData); //Конвертуємо string в integer 
			}
			catch (std::exception & e) // Ловимо помилку
			{
				std::cout << "Помилка зчитування з файлу у рядку " << i_Line << std::endl; // Виводимо повiдомення про помилку даних в рядку та продовжуємо зчитування
			}
			ml_Output.addBack(i_InputData); // Додаємо данi в список
		}
		ml_Output.deleteBack(); // Видаляємо зайвi данi (алгоритм зчитує останiй рядок двiчi)
		return ml_Output; // Повертаємо список з функцiї
	}
}

void FillFileTxt(std::string s_pathToFile, MyList ml_inputData)
{
	std::ofstream of_File(s_pathToFile); // Вiдкриваємо файл для запису
	if (of_File) //Якщо вдалося вiдкрити файл для запису
	{
		//Записуємо данi в файл
		for (int i = 0; i < ml_inputData.getSize(); i++)
			of_File << ml_inputData.getValue(ml_inputData.getByIndex(i)) << '\n';
		of_File.close(); // Закриваємо файл
	}
	else // Якщо не вдалося вiдкрити, чи створити файл
	{
		std::cout << "Помилка запису файлу" << std::endl;
	}
}

MyList ReadFromFileBin(std::string s_pathToFile)
{
	MyList ml_Out; // Список для виводу з функцiї
	ItemList il_Read; // Тимчасова структура елементу списку
	ItemList* p_item = new ItemList; // Створюємо вказiвник в пам'ятi 
	std::ifstream if_File(s_pathToFile, std::ios::binary); // Вiдкриваємо файл для бiнарного зчитування
	while (if_File.read((char*)&il_Read, sizeof(ItemList))) // поки є данi в файi
	{
		p_item = &il_Read; //Переносимо данi в структуру
		ml_Out.addBackStruct(p_item); // Додаємо елемент списку
	}
	return ml_Out; // Повертаємо список з функцiї
}

void FillFileBin(std::string s_pathToFile, MyList ml_inputData)
{
	ItemList il_OutData; // Тимчасовий елемент списку
	std::ofstream of_File(s_pathToFile, std::ios::binary); //Вiдкриваємо файл для запису
	for (int i = 0; i < ml_inputData.getSize(); i++) // Поки в вхiдному списку є елементи
	{
		il_OutData = *(ml_inputData.getByIndex(i)); // Отримуємо елемент списку по iндексу
		of_File.write((char*)&il_OutData, sizeof(ItemList)); // Записуємо данi в файл
	}
	of_File.close(); // Зачиняємо файл
}

void PrintList(MyList ml_inputData, bool b_lineOrColum)
{
	if(b_lineOrColum) // Вивiд списку в рядок через табуляцiю
		for (int i = 0; i < ml_inputData.getSize(); i++)
			std::cout << ml_inputData.getValue(ml_inputData.getByIndex(i)) << '\t';
	else
		for (int i = 0; i < ml_inputData.getSize(); i++) // Вiивiд списку в стовпчик
			std::cout << ml_inputData.getValue(ml_inputData.getByIndex(i)) << '\n';
}

