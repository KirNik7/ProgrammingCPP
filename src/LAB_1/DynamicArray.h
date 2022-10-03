#pragma once

struct DynamicArray
{
	int* Array;
	int Capacity;
	int Length;
};

void CreateArray(DynamicArray* dynamicArray);
void AddElement(DynamicArray* dynamicArray, int value);
void ResizeArray(DynamicArray* dynamicArray);
void ShowArray(DynamicArray* dynamicArray);
void GetArrayHandmade(DynamicArray* dynamicArray, int length);
void GetArrayRandom(DynamicArray* dynamicArray, int length);
void RemoveElement(DynamicArray* dynamicArray, int index);
void InsertElement(DynamicArray* dynamicArray, int value, int index);
void SortArray(DynamicArray* dynamicArray);
void LinearSearch(DynamicArray* dynamicArray, int value);
void BinarySearch(DynamicArray* dynamicArray, int value);