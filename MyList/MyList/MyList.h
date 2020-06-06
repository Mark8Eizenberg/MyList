#pragma once
#include <iostream>
/*������������ ����, �� �i����� � ���i ����i���i� �i�i����� ������'������ ������*/

//��������� �������� ������
struct ItemList
{
	int i_Data; //���i � ������
	ItemList* p_Prev; //����i���� �� �i���� ���i��
	ItemList* p_Next; //����i���� �� ������� ���i��
};


//���� ������
class MyList
{
private:
	// ��������, �� ��������i ������
	ItemList* il_Head = new ItemList; // "������" (�������) ������
	ItemList* il_Tail = new ItemList; // "��i�� (�i����) ������
	int size = 0; // ����i� ������ (�i���i��� �������i�)
public:
	// �������� �� ���� �������� ������

	// ����������� �����, ����������� ��� ��������i ������ ��'���� �����
	MyList(); 

	// �����i��� ������ �� ������i���
	bool isEmpty();

	// �������� ������ �������� ������
	void deleteBack(); 

	// ������ �������� � �i���� ������
	void addBack(int i_data /*�����, �� �����i��� ������*/); 

	// ����� ��������� �������� ���� ItemList ����� ����i���� (�����i��i� �� ����������� ���������� �� ������ � �i������ ����)
	void addBackStruct(ItemList* il_input);

	// �������� ����i� ������ � ������i integer
	int getSize(); 

	// �������� �������� ��������
	int getValue(ItemList* il_item/*����i���� �� ������� ������*/);
	
	//�������� ����i���� �� i������� �i ������
	struct ItemList* getByIndex(int i_index/*i����� � ������(���������� � ����)*/);
	
	//�������� ����i���� �� ������� ���i�� �������� ��������
	struct ItemList* findRight(ItemList* il_item/*����i���� �� ������� ������*/);
};
