#pragma once

//TODO: comments
struct ListItem
{
    /// @brief ��������� �������.
    ListItem* Next = nullptr;

    /// @brief ��������� �������.
    ListItem* Prev = nullptr;

    /// @brief �������� ��������.
    int Value = 0;
};

//TODO: comments
struct List
{
    /// @brief ��������� �� ������ ������� ������.
    ListItem* Head = nullptr;

    /// @brief ��������� �� ��������� ������� ������.
    ListItem* Tail = nullptr;

    /// @brief ����� ������.
    int Length = 0;
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
