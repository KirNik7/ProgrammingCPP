#include "DoubleLinkedList.h";
#include <iostream>;
#include <random>;
#include <ctime>;

using namespace std;

void CreateList(List* list)
{
	list->Head = nullptr;
	list->Tail = nullptr;
	list->Length = 0;
}

void AddElement(List* list, int value)
{
	ListItem* listItem = new ListItem;
	listItem->Value = value;
	listItem->Next = nullptr;
	listItem->Prev = nullptr;

	if (list->Head == nullptr)
	{
		list->Head = listItem;
		list->Tail = listItem;
	}
	else
	{
		list->Tail->Next = listItem;
		listItem->Prev = list->Tail;
		list->Tail = listItem;
	}

	list->Length++;
}

int GetElement(List* list, int index)
{
	ListItem* tempListItem = list->Head;

	for (int i = 0; i < index; i++)
	{
		tempListItem = tempListItem->Next;
	}

	return tempListItem->Value;
}

void RemoveElement(List* list, int index)
{
	if (index == 0)
	{
		if (list->Length == 1)
		{
			list->Head = nullptr;
			list->Length = 0;
			list->Tail = nullptr;
		}
		else
		{
			list->Head = list->Head->Next;
			list->Head->Prev = nullptr;
		}
	}
	else if (index == list->Length - 1)
	{
		list->Tail = list->Tail->Prev;
		list->Tail->Next = nullptr;
	}
	else
	{
		ListItem* tempListItem = list->Head;

		for (int i = 0; i < index; i++)
		{
			tempListItem = tempListItem->Next;
		}

		tempListItem->Prev->Next = tempListItem->Next;
		tempListItem->Next->Prev = tempListItem->Prev;
	}

	list->Length--;
}

void InsertElementInBegin(List* list, int value)
{
	ListItem* listItem = new ListItem;
	listItem->Value = value;
	listItem->Next = list->Head;
	listItem->Prev = nullptr;
	list->Head->Prev = listItem;
	list->Head = listItem;
	list->Length++;
}

void InsertElementInEnd(List* list, int value)
{
	ListItem* listItem = new ListItem;
	listItem->Value = value;
	listItem->Next = nullptr;
	listItem->Prev = list->Tail;
	list->Tail->Next = listItem;
	list->Tail = listItem;
	list->Length++;
}

void InsertElementAfterCertainElement(List* list, int index, int value)
{
	if (index == list->Length - 1)
	{
		InsertElementInEnd(list, value);
	}
	else
	{
		ListItem* listItem = new ListItem;
		listItem->Value = value;
		listItem->Next = nullptr;
		listItem->Prev = nullptr;

		ListItem* tempListItem = list->Head;

		for (int i = 0; i < index; i++)
		{
			tempListItem = tempListItem->Next;
		}

		listItem->Next = tempListItem->Next;
		listItem->Prev = tempListItem;
		tempListItem->Next->Prev = listItem;
		tempListItem->Next = listItem;
		list->Length++;
	}
}

void InsertElementBeforeCertainElement(List* list, int index, int value)
{
	if (index == 0)
	{
		InsertElementInBegin(list, value);
	}
	else
	{
		ListItem* listItem = new ListItem;
		listItem->Value = value;
		listItem->Next = nullptr;
		listItem->Prev = nullptr;

		ListItem* tempListItem = list->Head;

		for (int i = 0; i < index; i++)
		{
			tempListItem = tempListItem->Next;
		}

		listItem->Next = tempListItem;
		listItem->Prev = tempListItem->Prev;
		tempListItem->Prev->Next = listItem;
		tempListItem->Prev = listItem;
		list->Length++;
	}
}

void SortList(List* list)
{
	ListItem* tempListItem = list->Head;

	for (int i = 0; i < list->Length; i++)
	{
		for (int j = 0; j < list->Length - 1; j++)
		{
			if (tempListItem->Value > tempListItem->Next->Value)
			{
				int temp = tempListItem->Value;
				tempListItem->Value = tempListItem->Next->Value;
				tempListItem->Next->Value = temp;
			}

			tempListItem = tempListItem->Next;
		}

		tempListItem = list->Head;
	}
}

int LinearSearch(List* list, int value)
{
	ListItem* tempListItem = list->Head;

	for (int i = 0; i < list->Length; i++)
	{
		if (tempListItem->Value == value)
		{
			return i;
		}

		tempListItem = tempListItem->Next;
	}

	return -1;
}