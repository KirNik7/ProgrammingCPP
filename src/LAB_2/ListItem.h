#pragma once
#include "List.h";

/// @brief C�������� �������� ��������� ����������� ������.
struct Node
{
	int Data;
	Node* Next;
	Node* Prev;
};

int GetElement(List* list, int index);