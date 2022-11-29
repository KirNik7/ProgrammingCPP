#include "List.h";
#include "ListItem.h";
#include <iostream>;

using namespace std;

int main()
{
	List list;
	CreateList(&list);

	for (int i = 0; i < 10; i++)
	{
		AddElement(&list, i);
	}

	for (int i = 0; i < list.Length; i++)
	{
		cout << GetElement(&list, i) << endl;
	}

	RemoveElement(&list, 0);
	RemoveElement(&list, 1);
	RemoveElement(&list, 2);

	for (int i = 0; i < list.Length; i++)
	{
		cout << GetElement(&list, i) << endl;
	}

	return 0;
}