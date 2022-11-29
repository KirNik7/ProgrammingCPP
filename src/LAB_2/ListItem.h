#pragma once
#include "List.h";

/// @brief Cтруктура элемента линейного двусвязного списка.
struct Node
{
	int Data;
	Node* Next;
	Node* Prev;
};

int GetElement(List* list, int index);