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
	dynamicArray->Capacity *= 2;
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
	for (int i = 0; i < dynamicArray->Length; i++)
	{
		for (int j = 0; j < dynamicArray->Length - 1; j++)
		{
			if (dynamicArray->Array[j] > dynamicArray->Array[j + 1])
			{
				int temp = dynamicArray->Array[j];
				dynamicArray->Array[j] = dynamicArray->Array[j + 1];
				dynamicArray->Array[j + 1] = temp;
			}
		}
	}
}

 int LinearSearch(DynamicArray* dynamicArray, int value)
{
	bool isFind = false;

	for (int i = 0; i < dynamicArray->Length; i++)
	{
		if (dynamicArray->Array[i] == value)
		{
			return i;
		}
	}
	return -1;
}

int BinarySearch(DynamicArray* dynamicArray, int value)
{
	int left = 0;
	int right = dynamicArray->Length;
	int middle;
	bool isFind = false;

	while ((left <= right) && (isFind != true))
	{
		middle = (left + right) / 2;

		if (dynamicArray->Array[middle] == value)
		{
			isFind = true;
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

	if (isFind == true)
	{
		return middle;
	}
	else
	{
		return -1;
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