#include "MyList.h"

MyList::MyList()
{
	//Зв'язуємо початок та кiнець списку один з одним
	il_Head->p_Next = il_Tail;
	il_Tail->p_Prev = il_Head;
	il_Head->p_Prev = il_Tail->p_Next = nullptr; // Вказуємо, що початок та кiнець списку не мають сусiдiв, окрiм один одного
}

bool MyList::isEmpty()
{
	if (il_Head->p_Next == il_Tail) //Якщо елементи початку та кiiнця зв'язанi мiж собою,
		return true; //то повертаємо iстинне значення, адже список пустий
	return false; // в iншому випадку, список не пустий, повертаємо не iстинне значення 
}

void MyList::deleteBack()
{
	if (il_Head->p_Next == il_Tail) //Перевiрка чи не пустий список
		std::cout << "Немає елементiв для видалення" << std::endl;
	else
	{
		this->size--; //Зменшуємо значення розмiру списку на 1
		ItemList* p_DeletingItem = this->il_Tail->p_Prev; // Створюємо вказiвник на еемент, що буде видалено
		ItemList* p_PrevItem = p_DeletingItem->p_Prev; // Створюємо вказiвник на елемент, сусiда злiва для видаленого елементу
		// Виклчаємо елемент що видаляється зi списку
		p_PrevItem->p_Next = this->il_Tail; 
		this->il_Tail->p_Prev = p_PrevItem;
		// Чистимо пам'ять, котру займає елемент, що видаляється
		delete p_DeletingItem;
	}

}

void MyList::addBack(int i_data)
{
	this->size++; //Збiльшуємо значення розмiру списку на 1
	ItemList* p_CurentItem = new ItemList; // Вказiвник на елемент, що додається (видiляємо пам'ять)
	ItemList* p_PrevItem = il_Tail->p_Prev; // Вказiвник на попереднiй елемент
	p_CurentItem->i_Data = i_data; // Додаємо значення для елементу
	p_CurentItem->p_Next = il_Tail; // Вказуємо на "хвiст" списку, як наступний елемент
	p_CurentItem->p_Prev = il_Tail->p_Prev; // Вказуємо на попереднiй елемент списку
	p_PrevItem->p_Next = p_CurentItem; //Вказуємо попередньому елементу списку елемент, що додається, як правого сусiда
	il_Tail->p_Prev = p_CurentItem; // Закриваємо список, вказуючи кiнцевому елементу, на елемент, що додається
}

void MyList::addBackStruct(ItemList* il_input)
{
	this->size++; //Збiльшуємо значення розмiру списку на 1
	ItemList* p_CurentItem = new ItemList; // Вказiвник на елемент, що додається (видiляємо пам'ять)
	ItemList* p_PrevItem = il_Tail->p_Prev; // Вказiвник на попереднiй елемент
	p_CurentItem->i_Data = il_input->i_Data; // Додаємо значення для елементу
	p_CurentItem->p_Prev = p_PrevItem; // Вказуємо на попереднiй елемент списку
	p_CurentItem->p_Next = il_Tail; // Вказуємо на "хвiст" списку, як наступний елемент
	p_PrevItem->p_Next = p_CurentItem; //Вказуємо попередньому елементу списку елемент, що додається, як правого сусiда
	il_Tail->p_Prev = p_CurentItem; // Закриваємо список, вказуючи кiнцевому елементу, на елемент, що додається
}

int MyList::getSize()
{
	return this->size; //Повертаємо кiлькiсть елементiв
}

int MyList::getValue(ItemList* il_item)
{
	if (il_item != nullptr) //перевiряємо, чи не пустий вказiвник прийшов на вхiд
		return il_item->i_Data; // Якщо нi, повертаємо значення елементу 
	//Нижче, описанi дiї, що не вiдповiдають попередньому умовному оператору
	std::cout << "Невiрний вказiвник" << std::endl; // Вивiд в консолi помилки
}

ItemList* MyList::getByIndex(int i_index)
{
	// Перевiрка на неправильнiсть iндексу
	if (this->size < i_index+1 || i_index < 0) 
		std::cout << "Вихiд за межi списку" << std::endl;
	else if (this->isEmpty())
		std::cout << "Список пустий" << std::endl;
	// Якщо iндекс правильний
	else
	{
		ItemList* p_CurrentItem = this->il_Head; // Вказiвник, що повертається, iнiцiалiзується, як початок списку
		for (int i = 0; i < i_index+1; i++) //Цикл для пошуку за iндексом
			p_CurrentItem = findRight(p_CurrentItem); //Приклад використання функцiї пошуку правого сусiда, 
													  //також можна використати конструкцiю p_CurrentItem = p_CurrentItem->p_Next;  
		return p_CurrentItem; // Повертаємо знайдений вказiвник
	}
	return nullptr; // При неправильностi iндексу, повертаємо нульовий вказiвник
}

ItemList* MyList::findRight(ItemList* il_item)
{
	//Перевiрка вхiдного вказiвника на помилки
	if (il_item == nullptr)
		std::cout << "Невiрниий вказiвник" << std::endl;
	else if (il_item == this->il_Tail)
		std::cout << "Неочiкуваний кiнець списку" << std::endl;
	else
	// Якщо вказiвник вiрний
		return il_item = il_item->p_Next; //повертаємо значення правого сусiда для обраного елементу
	// Якщо вказiвник не вiрний
	return nullptr; // Повертаємо нульовий вказiвник
}

