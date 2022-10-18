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
void ShowArray(DynamicArray* dynamicArray);
void GetArrayByUser(DynamicArray* dynamicArray, int length);
void GetRandomArray(DynamicArray* dynamicArray, int length);
void SortArray(DynamicArray* dynamicArray);
void LinearSearch(DynamicArray* dynamicArray, int value);
void BinarySearch(DynamicArray* dynamicArray, int value);