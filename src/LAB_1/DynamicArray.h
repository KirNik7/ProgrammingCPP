#pragma once

/// @brief ������ ���������� � ������������ �������.
struct DynamicArray
{
	int* Array;
	int Capacity;
	int Length;
};

/// @brief ��������� �������� ������������� �������.
/// @param dynamicArray ������������ ������.
void CreateArray(DynamicArray* dynamicArray);

/// @brief ��������� ���������� ������ �������� � ������������ ������.
/// @param dynamicArray ������������ ������.
/// @param value ��������, ������� ����� �������� � ������������ ������.
void AddElement(DynamicArray* dynamicArray, int value);

/// @brief ��������� �������� ���������� ��������� � ������������ �������.
/// @param dynamicArray ������������ ������.
/// @param index ������ ��������, ������� ����� �������.
void RemoveElement(DynamicArray* dynamicArray, int index);

/// @brief ��������� ������� ������ �������� � ������������ ������.
/// @param dynamicArray ������������ ������.
/// @param value ��������, ������� ����� ��������.
/// @param index ������ ��������, ����� �������� ����� �������� ����� �������.
void InsertElement(DynamicArray* dynamicArray, int value, int index);

/// @brief ��������� ��������� ������� ������������� �������.
/// @param dynamicArray ������������ ������.
void ResizeArray(DynamicArray* dynamicArray);

/// @brief ��������� ���������� ������������� ������� ���������� ����������.
/// @param dynamicArray ������������ ������.
/// @param length ����� ������������� �������.
void GetRandomArray(DynamicArray* dynamicArray, int length);

/// @brief ��������� ���������� ������������� �������.
/// @param dynamicArray ������������ ������.
void SortArray(DynamicArray* dynamicArray);

/// @brief ��������� �������� ����� �������� � ������������ �������.
/// @param dynamicArray ������������ ������.
/// @param value ������� ��������.
/// @return ������ �������� � ������� ���������.
int LinearSearch(DynamicArray* dynamicArray, int value);

/// @brief ��������� �������� ����� �������� � ������������ �������.
/// @param dynamicArray ������������ ������.
/// @param value ������� ��������.
/// @return ������ �������� � ������� ���������.
int BinarySearch(DynamicArray* dynamicArray, int value);