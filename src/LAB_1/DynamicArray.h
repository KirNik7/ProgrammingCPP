#pragma once

struct DynamicArray
{
	int* Array;
	int Capacity;
	int Length;
};

void CreateArray(DynamicArray* dynamicArray);
void AddElement(DynamicArray* dynamicArray, int value);
void RemoveElement(DynamicArray* dynamicArray, int index);
void InsertElement(DynamicArray* dynamicArray, int value, int index);
void ResizeArray(DynamicArray* dynamicArray);
void GetRandomArray(DynamicArray* dynamicArray, int length);
void SortArray(DynamicArray* dynamicArray);
int LinearSearch(DynamicArray* dynamicArray, int value);
int BinarySearch(DynamicArray* dynamicArray, int value);