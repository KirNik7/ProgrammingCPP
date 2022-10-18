#include "DynamicArray.h"
#include <iostream>
#include <random>
#include <ctime>
using namespace std;

void CreateArray(DynamicArray* dynamicArray)
{
	int capacity = 4;
	dynamicArray->Capacity = capacity;
	dynamicArray->Length = 0;
	dynamicArray->Array = new int[dynamicArray->Capacity];
}

void ResizeArray(DynamicArray* dynamicArray)
{
	dynamicArray->Capacity += 10;

	int* tempArray = new int[dynamicArray->Capacity];

	for (int i = 0; i < dynamicArray->Length - 1; i++)
	{
		tempArray[i] = dynamicArray->Array[i];
	}

	delete[] dynamicArray->Array;
	dynamicArray->Array = tempArray;
}


void AddElement(DynamicArray* dynamicArray, int value)
{
	dynamicArray->Length++;

	if (dynamicArray->Length >= dynamicArray->Capacity)
	{
		ResizeArray(dynamicArray);
	}

	dynamicArray->Array[dynamicArray->Length - 1] = value;
}

void ShowArray(DynamicArray* dynamicArray)
{
	for (int i = 0; i < dynamicArray->Length; i++)
	{
		cout << dynamicArray->Array[i] << " ";
	}

	cout << "\n" << endl;
}

void GetArrayHandmade(DynamicArray* dynamicArray, int length)
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

void GetRandomArray(DynamicArray* dynamicArray, int length)
{
	srand(time(NULL));

	for (int i = 0; i < length; i++)
	{
		AddElement(dynamicArray, rand());
	}
}

void InsertElement(DynamicArray* dynamicArray, int value, int index)
{
	dynamicArray->Length++;

	if (dynamicArray->Length >= dynamicArray->Capacity)
	{
		ResizeArray(dynamicArray);
	}

	for (int i = dynamicArray->Length; i > index; i--)
	{
		dynamicArray->Array[i] = dynamicArray->Array[i - 1];
	}

	dynamicArray->Array[index] = value;
}

void SortArray(DynamicArray* dynamicArray)
{
	for (int i = 0; i < dynamicArray->Length; i++) {
		for (int j = 0; j < dynamicArray->Length - 1; j++) {
			if (dynamicArray->Array[j] > dynamicArray->Array[j + 1]) {
				int temp = dynamicArray->Array[j];
				dynamicArray->Array[j] = dynamicArray->Array[j + 1];
				dynamicArray->Array[j + 1] = temp;
			}
		}
	}
}

void LinearSearch(DynamicArray* dynamicArray, int value)
{
	bool flag = false;

	for (int i = 0; i < dynamicArray->Length; i++)
	{
		if (dynamicArray->Array[i] == value)
		{
			cout << "������� " << value << " ������ �� ������� " << i << endl;
			flag = true;
			return;
		}
	}

	if (flag == false)
	{
		cout << "������� �� ������" << endl;
	}
}

void BinarySearch(DynamicArray* dynamicArray, int value)
{
	int left = 0;
	int right = dynamicArray->Length;
	int middle;
	bool flag = false;

	while ((left <= right) && (flag != true))
	{
		middle = (left + right) / 2;

		if (dynamicArray->Array[middle] == value)
		{
			flag = true;
		}
		if (dynamicArray->Array[middle] > value)
		{
			right = middle - 1;
		}
		if (dynamicArray->Array[middle] < value)
		{
			left = middle + 1;
		}
	}

	if (flag == true)
	{
		cout << "������� " << value << " ������ �� ������� " << middle << endl;
	}
	else
	{
		cout << "������� �� ������" << endl;
	}
}

void RemoveElement(DynamicArray* dynamicArray, int index)
{
	for (int i = index; i < dynamicArray->Length - 1; i++)
	{
		dynamicArray->Array[i] = dynamicArray->Array[i + 1];
	}

	dynamicArray->Length -= 1;
}