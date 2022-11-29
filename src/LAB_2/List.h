#pragma once
#include "ListItem.h";

/// @brief ��������� ��������� ����������� ������.
struct List
{
	Node* Head;
	Node* Tail;
	int Length;
};

/// @brief �������� ��������� ����������� ������.
/// @param list - ��������� �� �������� ���������� ������.
void CreateList(List* list);

/// @brief ���������� �������� � ����� ��������� ����������� ������.
/// @param list - ��������� �� �������� ���������� ������.
/// @param value - �������� ��������.
void AddElement(List* list, int value);

/// @brief �������� �������� �� ��������� ����������� ������.
/// @param list - ��������� �� �������� ���������� ������.
/// @param index - ������ ��������.
void RemoveElement(List* list, int index);

/// @brief ������� �������� � ������ ��������� ����������� ������.
/// @param list - ��������� �� �������� ���������� ������.
/// @param value - �������� ��������.
void InsertElementInBegin(List* list, int value);

/// @brief ������� �������� � ����� ��������� ����������� ������.
/// @param list - ��������� �� �������� ���������� ������.
/// @param value - �������� ��������.
void InsertElementInEnd(List* list, int value);

/// @brief ������� �������� � �������� ���������� ������ ����� ������������� ��������.
/// @param list - ��������� �� �������� ���������� ������.
/// @param value - �������� ��������.
/// @param index - ������ ��������.
void InsertElementAfterCertainElement(List* list, int value, int index);

/// @brief ������� �������� � �������� ���������� ������ ����� ������������ ���������.
/// @param list - ��������� �� �������� ���������� ������.
/// @param value - �������� ��������.
/// @param index - ������ ��������.
void InsertElementBeforeCertainElement(List* list, int value, int index);

/// @brief ���������� ��������� ����������� ������.
/// @param list - ��������� �� �������� ���������� ������.
void SortList(List* list);

/// @brief �������� ����� �������� � �������� ���������� ������.
/// @param list - ��������� �� �������� ���������� ������.
/// @param value - �������� ��������.
/// @return ���������� ������ ��������.
/// @return ���������� -1, ���� ������� �� ������.
int LinearSearch(List* list, int value);
