#pragma once

/// @brief ������ ���������� � ������������ �������.
struct DynamicArray
{
	/// @brief ������ �������.
	int* Array;

	/// @brief ������ ������������� �������.
	int Capacity;

	/// @brief ����� ������������� �������.
	int Length = 0;
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

/// @brief ��������� ���������� ������� ������������� �������.
/// @param dynamicArray ������������ ������.
void ReductionArray(DynamicArray* dynamicArray);

/// @brief ��������� ���������� ������������� �������.
/// @param dynamicArray ������������ ������.
void UpdateArray(DynamicArray* dynamicArray);

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