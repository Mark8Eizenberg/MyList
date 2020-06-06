#include "MyList.h"

MyList::MyList()
{
	//��'����� ������� �� �i���� ������ ���� � �����
	il_Head->p_Next = il_Tail;
	il_Tail->p_Prev = il_Head;
	il_Head->p_Prev = il_Tail->p_Next = nullptr; // �������, �� ������� �� �i���� ������ �� ����� ���i�i�, ���i� ���� ������
}

bool MyList::isEmpty()
{
	if (il_Head->p_Next == il_Tail) //���� �������� ������� �� �ii��� ��'����i �i� �����,
		return true; //�� ��������� i������ ��������, ���� ������ ������
	return false; // � i����� �������, ������ �� ������, ��������� �� i������ �������� 
}

void MyList::deleteBack()
{
	if (il_Head->p_Next == il_Tail) //�����i��� �� �� ������ ������
		std::cout << "���� �������i� ��� ���������" << std::endl;
	else
	{
		this->size--; //�������� �������� ����i�� ������ �� 1
		ItemList* p_DeletingItem = this->il_Tail->p_Prev; // ��������� ����i���� �� ������, �� ���� ��������
		ItemList* p_PrevItem = p_DeletingItem->p_Prev; // ��������� ����i���� �� �������, ���i�� ��i�� ��� ���������� ��������
		// �������� ������� �� ����������� �i ������
		p_PrevItem->p_Next = this->il_Tail; 
		this->il_Tail->p_Prev = p_PrevItem;
		// ������� ���'���, ����� ����� �������, �� �����������
		delete p_DeletingItem;
	}

}

void MyList::addBack(int i_data)
{
	this->size++; //��i������ �������� ����i�� ������ �� 1
	ItemList* p_CurentItem = new ItemList; // ����i���� �� �������, �� �������� (���i����� ���'���)
	ItemList* p_PrevItem = il_Tail->p_Prev; // ����i���� �� ��������i� �������
	p_CurentItem->i_Data = i_data; // ������ �������� ��� ��������
	p_CurentItem->p_Next = il_Tail; // ������� �� "��i��" ������, �� ��������� �������
	p_CurentItem->p_Prev = il_Tail->p_Prev; // ������� �� ��������i� ������� ������
	p_PrevItem->p_Next = p_CurentItem; //������� ������������ �������� ������ �������, �� ��������, �� ������� ���i��
	il_Tail->p_Prev = p_CurentItem; // ��������� ������, �������� �i������� ��������, �� �������, �� ��������
}

void MyList::addBackStruct(ItemList* il_input)
{
	this->size++; //��i������ �������� ����i�� ������ �� 1
	ItemList* p_CurentItem = new ItemList; // ����i���� �� �������, �� �������� (���i����� ���'���)
	ItemList* p_PrevItem = il_Tail->p_Prev; // ����i���� �� ��������i� �������
	p_CurentItem->i_Data = il_input->i_Data; // ������ �������� ��� ��������
	p_CurentItem->p_Prev = p_PrevItem; // ������� �� ��������i� ������� ������
	p_CurentItem->p_Next = il_Tail; // ������� �� "��i��" ������, �� ��������� �������
	p_PrevItem->p_Next = p_CurentItem; //������� ������������ �������� ������ �������, �� ��������, �� ������� ���i��
	il_Tail->p_Prev = p_CurentItem; // ��������� ������, �������� �i������� ��������, �� �������, �� ��������
}

int MyList::getSize()
{
	return this->size; //��������� �i���i��� �������i�
}

int MyList::getValue(ItemList* il_item)
{
	if (il_item != nullptr) //�����i�����, �� �� ������ ����i���� ������� �� ��i�
		return il_item->i_Data; // ���� �i, ��������� �������� �������� 
	//�����, ������i �i�, �� �� �i����i����� ������������ �������� ���������
	std::cout << "���i���� ����i����" << std::endl; // ���i� � ������i �������
}

ItemList* MyList::getByIndex(int i_index)
{
	// �����i��� �� ����������i��� i������
	if (this->size < i_index+1 || i_index < 0) 
		std::cout << "���i� �� ���i ������" << std::endl;
	else if (this->isEmpty())
		std::cout << "������ ������" << std::endl;
	// ���� i����� ����������
	else
	{
		ItemList* p_CurrentItem = this->il_Head; // ����i����, �� �����������, i�i�i��i������, �� ������� ������
		for (int i = 0; i < i_index+1; i++) //���� ��� ������ �� i�������
			p_CurrentItem = findRight(p_CurrentItem); //������� ������������ �����i� ������ ������� ���i��, 
													  //����� ����� ����������� ���������i� p_CurrentItem = p_CurrentItem->p_Next;  
		return p_CurrentItem; // ��������� ��������� ����i����
	}
	return nullptr; // ��� �������������i i������, ��������� �������� ����i����
}

ItemList* MyList::findRight(ItemList* il_item)
{
	//�����i��� ��i����� ����i����� �� �������
	if (il_item == nullptr)
		std::cout << "���i����� ����i����" << std::endl;
	else if (il_item == this->il_Tail)
		std::cout << "����i������� �i���� ������" << std::endl;
	else
	// ���� ����i���� �i����
		return il_item = il_item->p_Next; //��������� �������� ������� ���i�� ��� �������� ��������
	// ���� ����i���� �� �i����
	return nullptr; // ��������� �������� ����i����
}

