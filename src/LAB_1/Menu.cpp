#include <iostream>
#include "DynamicArray.h"
#include "Menu.h"

using namespace std;

bool ArrayIsSorted = false;
bool ArrayIsExists = false;

void InputValueInMenu(int* value)
{
	while (true)
	{
		cin >> *value;

		if (!cin.fail()) return;
		
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "�������� ��������, ������� �����: ";
	}
}

void CreateArrayInMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsExists == false)
	{
		CreateArray(dynamicArray);
		ArrayIsExists = true;
	}
	else
	{
		cout << "������ ��� ����������" << endl;
		return;
	}

	bool isHaveNotCount = true;
	int count;
	cout << "���������� ��������� ������� = ";

	while (isHaveNotCount)
	{
		InputValueInMenu(&count);

		if (count <= 0)
		{
			cout << "���������� ��������� � ������� �� ������ ���� ������ 1." << endl;
			continue;
		}

		isHaveNotCount = false;
	}

	bool isHaveNotChoice = true;
	cout << "\n��������:" << endl;
	cout << "1. ������ �� ���������� ����������" << endl;
	cout << "2. ������ ���� �������� ��� ��������� �������" << endl;

	while (isHaveNotChoice)
	{
		int key;
		InputValueInMenu(&key);

		switch (key)
		{
		case 1:
			GetRandomArray(dynamicArray, count);
			isHaveNotChoice = false;
			break;
		case 2:
			GetArrayByUserInMenu(dynamicArray, count);
			isHaveNotChoice = false;
			break;
		default:
			cout << "�������� ��������.";
			break;
		}
	}

	cout << "\n������ ������.\n";
}

void AddElementInMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsExists == false)
	{
		cout << "������ �� ����������, ������� ����� ������� ������." << endl;
		return;
	}

	int value;
	cout << "�������� ������ �������� = ";
	InputValueInMenu(&value);
	AddElement(dynamicArray, value);
	ArrayIsSorted = false;
	cout << "\n����� ������� �������� � ������.\n";
}

void RemoveElementInMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsExists == false)
	{
		cout << "������ �� ����������, ������� ����� ������� ������." << endl;
		return;
	}

	int index;

	while (true)
	{
		cout << "������ ��������, ������� ����� ������� = ";
		InputValueInMenu(&index);

		if (index < 0)
		{
			cout << "������ ������ ���� ������ ��� ����� ����." << endl;
			continue;
		}
		if (index >= dynamicArray->Length)
		{
			cout << "������ ������ ���� ������ ����� �������." << endl;
			continue;
		}

		break;
	}

	RemoveElement(dynamicArray, index);

	if (dynamicArray->Length == 0)
	{
		ArrayIsExists = false;
	}

	cout << "\n��������� ������� ��� ������ �������.\n";
}

void InsertELementInMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsExists == false)
	{
		cout << "������ �� ����������, ������� ����� ������� ������." << endl;
		return;
	}

	int value;
	int index;
	int isHaveNotIndex = true;
	cout << "�������� ������ �������� = ";
	InputValueInMenu(&value);
	cout << "�������� �������:" << endl;
	cout << "1. � ������ �������" << endl;
	cout << "2. ����� ������������� ��������" << endl;
	cout << "3. � ����� �������" << endl;

	while (isHaveNotIndex)
	{
		int key;

		InputValueInMenu(&key);

		switch (key)
		{
		case 1:
			index = 0;
			InsertElement(dynamicArray, value, index);
			ArrayIsSorted = false;
			isHaveNotIndex = false;
			break;
		case 2:
			cout << "������ �������, ����� �������� ����� ����������� ����� ������� = ";
			InputValueInMenu(&index);
			index++;

			if (index < 0)
			{
				cout << "������ ������� ������ ���� ������ ��� ����� 0." << endl;
				break;
			}

			if (index > dynamicArray->Length)
			{
				cout << "���������� ��������� ������� �� ��� �����." << index << endl;
				break;
			}

			InsertElement(dynamicArray, value, index);
			ArrayIsSorted = false;
			isHaveNotIndex = false;
			break;
		case 3:
			index = dynamicArray->Length;
			InsertElement(dynamicArray, value, index);
			ArrayIsSorted = false;
			isHaveNotIndex = false;
			break;
		default:
			cout << "�������� ��������.";
			break;
		}
	}

	cout << "\n����� ������� �������� �� ��������� �����.\n";
}

void SortArrayInMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsExists == false)
	{
		cout << "������ �� ����������, ������� ����� ������� ������." << endl;
		return;
	}

	SortArray(dynamicArray);
	ArrayIsSorted = true;
	cout << "\n������ ������������.\n";
}

void LinearSearchInMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsExists == false)
	{
		cout << "������ �� ����������, ������� ����� ������� ������." << endl;
		return;
	}

	int value;
	cout << "�������� ��������, ������� ����� ����� = ";
	InputValueInMenu(&value);

	if (LinearSearch(dynamicArray, value) == -1)
	{
		cout << "������� �� ������" << endl;
	}
	else
	{
		cout << "������� " << value << " ������ �� ������� " <<
			LinearSearch(dynamicArray, value) << endl;
	}
}

void BinarySearchInMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsExists == false)
	{
		cout << "������ �� ����������, ������� ����� ������� ������." << endl;
		return;
	}

	if (ArrayIsSorted == false)
	{
		cout << "������ ��� �� ������������." << endl;
		return;
	}

	int value;
	cout << "�������� ��������, ������� ����� ����� = ";
	InputValueInMenu(&value);
	if (BinarySearch(dynamicArray, value) == -1)
	{
		cout << "������� �� ������" << endl;
	}

	else
	{
		cout << "������� " << value << " ������ �� ������� " <<
			BinarySearch(dynamicArray, value) << endl;
	}
}

void GetArrayByUserInMenu(DynamicArray* dynamicArray, int length)
{
	int value;

	for (int i = 0; i < length; i++)
	{
		cout << i << " ������� ������� = ";
		cin >> value;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		AddElement(dynamicArray, value);
	}
}

void PrintArrayInMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsExists)
	{
		for (int i = 0; i < dynamicArray->Length; i++)
		{
			cout << dynamicArray->Array[i] << " ";
		}
	}

	else
	{
		cout << "�� ������.";
	}
}