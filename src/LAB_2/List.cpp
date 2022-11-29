#include "List.h";
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
	Node* node = new Node;
	node->Data = value;
	node->Next = nullptr;
	node->Prev = nullptr;

	if (list->Head == nullptr)
	{
		list->Head = node;
		list->Tail = node;
	}
	else
	{
		list->Tail->Next = node;
		node->Prev = list->Tail;
		list->Tail = node;
	}

	list->Length++;
}

void RemoveElement(List* list, int index)
{
	if (index == 0)
	{
		list->Head = list->Head->Next;
		list->Head->Prev = nullptr;
	}
	else if (index == list->Length - 1)
	{
		list->Tail = list->Tail->Prev;
		list->Tail->Next = nullptr;
	}
	else
	{
		Node* tempNode = list->Head;

		for (int i = 0; i < index; i++)
		{
			tempNode = tempNode->Next;
		}

		tempNode->Prev->Next = tempNode->Next;
		tempNode->Next->Prev = tempNode->Prev;
	}

	list->Length--;
}

void InsertElementInBegin(List* list, int value)
{
	Node* node = new Node;
	node->Data = value;
	node->Next = list->Head;
	node->Prev = nullptr;
	list->Head->Prev = node;
	list->Head = node;
	list->Length++;
}

void InsertElementInEnd(List* list, int value)
{
	Node* node = new Node;
	node->Data = value;
	node->Next = nullptr;
	node->Prev = list->Tail;
	list->Tail->Next = node;
	list->Tail = node;
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
		Node* node = new Node;
		node->Data = value;
		node->Next = nullptr;
		node->Prev = nullptr;

		Node* tempNode = list->Head;

		for (int i = 0; i < index; i++)
		{
			tempNode = tempNode->Next;
		}

		node->Next = tempNode->Next;
		node->Prev = tempNode;
		tempNode->Next->Prev = node;
		tempNode->Next = node;
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
		Node* node = new Node;
		node->Data = value;
		node->Next = nullptr;
		node->Prev = nullptr;

		Node* tempNode = list->Head;

		for (int i = 0; i < index; i++)
		{
			tempNode = tempNode->Next;
		}

		node->Next = tempNode;
		node->Prev = tempNode->Prev;
		tempNode->Prev->Next = node;
		tempNode->Prev = node;
		list->Length++;
	}
}

void SortList(List* list)
{
	Node* tempNode = list->Head;

	for (int i = 0; i < list->Length; i++)
	{
		for (int j = 0; j < list->Length - 1; j++)
		{
			if (tempNode->Data > tempNode->Next->Data)
			{
				int temp = tempNode->Data;
				tempNode->Data = tempNode->Next->Data;
				tempNode->Next->Data = temp;
			}

			tempNode = tempNode->Next;
		}

		tempNode = list->Head;
	}
}

int LinearSearch(List* list, int value)
{
	Node* tempNode = list->Head;

	for (int i = 0; i < list->Length; i++)
	{
		if (tempNode->Data == value)
		{
			return i;
		}

		tempNode = tempNode->Next;
	}

	return -1;
}