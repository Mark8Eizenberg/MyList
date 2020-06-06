#pragma once
#include <iostream>
/*Заголовочний файл, що мiстить в собi реалiзацiю лiнiйного двохзв'язного списку*/

//Структура елементу списку
struct ItemList
{
	int i_Data; //Данi в списку
	ItemList* p_Prev; //Вказiвник на лiвого сусiда
	ItemList* p_Next; //Вказiвник на правого сусiда
};


//Клас списку
class MyList
{
private:
	// Елементи, що прихованi класом
	ItemList* il_Head = new ItemList; // "Голова" (початок) списку
	ItemList* il_Tail = new ItemList; // "Хвiст (кiнець) списку
	int size = 0; // Розмiр списку (кiлькiсть елементiв)
public:
	// Елементи до яких надається доступ

	// Конструктор класу, викликається при створеннi нового об'єкту класу
	MyList(); 

	// Перевiрка списку на порожнiсть
	bool isEmpty();

	// Видалити останнє значення списку
	void deleteBack(); 

	// Додати значення в кiнець списку
	void addBack(int i_data /*Число, що необхiдно додати*/); 

	// Метод додавання елементу типу ItemList через вказiвник (необхiднiй дл правильного зчитування та запису в бiнарний файл)
	void addBackStruct(ItemList* il_input);

	// Отримати розмiр списку у форматi integer
	int getSize(); 

	// Отримати значення елемента
	int getValue(ItemList* il_item/*Вказiвник на елемент списку*/);
	
	//Отримати вказiвник за iндексом зi списку
	struct ItemList* getByIndex(int i_index/*iндекс у списку(починається з нуля)*/);
	
	//Отримати вказiвник на правого сусiда обраного елементу
	struct ItemList* findRight(ItemList* il_item/*Вказiвник на елемент списку*/);
};
