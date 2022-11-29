#include "List.h";
#include "ListItem.h";
#include <iostream>;

using namespace std;

int GetElement(List* list, int index)
{
	Node* tempNode = list->Head;
	
	for (int i = 0; i < index; i++)
	{
		tempNode = tempNode->Next;
	}

	return tempNode->Data;
}