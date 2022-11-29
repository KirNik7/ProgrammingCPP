#pragma once

/// @brief ��������� ������� ����� �������� � ����.
/// @param value �������� � ����.
void InputValueInMenu(int* value);

/// @brief ��������� �������� ������� ����� ����.
/// @param dynamicArray ������������ ������.
void CreateArrayInMenu(DynamicArray* dynamicArray);

/// @brief ��������� ���������� ������ �������� � ������������ ������ ����� ����.
/// @param dynamicArray ������������ ������.
void AddElementInMenu(DynamicArray* dynamicArray);

/// @brief ��������� �������� �������� ������������� ������� ����� ����.
/// @param dynamicArray ������������ ������.
void RemoveElementInMenu(DynamicArray* dynamicArray);

/// @brief ��������� ������� ������ �������� � ������������ ������ ����� ����.
/// @param dynamicArray ������������ ������.
void InsertELementInMenu(DynamicArray* dynamicArray);

/// @brief ��������� ���������� ������������� ������� ����� ����.
/// @param dynamicArray ������������ ������.
void SortArrayInMenu(DynamicArray* dynamicArray);

/// @brief ��������� �������� ����� �������� � ������������ ������� ����� ����.
/// @param dynamicArray ������������ ������.
void LinearSearchInMenu(DynamicArray* dynamicArray);

/// @brief ��������� �������� ����� �������� � ������������ ������� ����� ����.
/// @param dynamicArray ������������ ������.
void BinarySearchInMenu(DynamicArray* dynamicArray);

/// @brief ��������� ��������� ���������������� ��������� ������������� ������� ����� ����.
/// @param dynamicArray ������������ ������.
/// /// @param length ����� ������������� �������.
void GetArrayByUserInMenu(DynamicArray* dynamicArray, int length);

/// @brief ��������� ��������� �������� ������������ �������.
/// @return ���������� �������� ������������� �������.
void PrintArrayInMenu(DynamicArray* dynamicArray);