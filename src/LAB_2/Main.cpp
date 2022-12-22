#include "DoubleLinkedList.h";
#include <iostream>;

using namespace std;

void PrintList(List* list)
{
	if (list->Head == nullptr)
	{
		cout << "Список не существует." << endl;
	}
	else
	{
		ListItem* tempListItem = list->Head;

		while (tempListItem != nullptr)
		{
			cout << tempListItem->Value << " ";
			tempListItem = tempListItem->Next;
		}

		cout << endl;
	}
}

void InputValue(int* value)
{
	while (true)
	{
		cin >> *value;

		if (!cin.fail()) return;

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Неверное значение, введите число: ";
	}
}

void GetList(List* list, int length)
{
	int value;

	for (int i = 0; i < length; i++)
	{
		cout << i << " элемент списка = ";
		cin >> value;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		AddElement(list, value);
	}
}

void GetRandomList(List* list, int length)
{
	srand(time(nullptr));

	for (int i = 0; i < length; i++)
	{
		AddElement(list, rand());
	}
}

void CreateListInMenu(List* list)
{
	if (list->Length == 0)
	{
		CreateList(list);
	}
	else
	{
		cout << "Список уже существует" << endl;
		return;
	}

	bool isHaveNotCount = true;
	int count;
	cout << "Количество элементов списка = ";

	while (isHaveNotCount)
	{
		InputValue(&count);

		if (count <= 0)
		{
			cout << "Количество элементов в списке не должно быть меньше 1." << endl;
			continue;
		}

		isHaveNotCount = false;
	}

	bool isHaveNotChoice = true;
	cout << "\nВыберите:" << endl;
	cout << "1. Список со случайными значениями" << endl;
	cout << "2. Ввести свои значения для элементов списка" << endl;

	while (isHaveNotChoice)
	{
		int key;
		InputValue(&key);

		switch (key)
		{
		case 1:
			GetRandomList(list, count);
			isHaveNotChoice = false;
			break;
		case 2:
			GetList(list, count);
			isHaveNotChoice = false;
			break;
		default:
			cout << "Неверное значение.";
			break;
		}
	}

	cout << "\nМассив создан.\n";
}

void ChoiceInsertMode(List* list)
{
	int index = 0;
	int mode = 0;
	int value = 0;
	while (true)
	{
		cout << "Выберите режим вставки: " << endl;
		cout << "1. Вставить в начало списка" << endl;
		cout << "2. Вставить в конец списка" << endl;
		cout << "3. Вставить после определенного элемента" << endl;
		cout << "4. Вставить перед определенным элементом" << endl;
		cout << "Ваш выбор: ";
		InputValue(&mode);
		if ((mode > 0) && (mode <= 4))
		{
			break;
		}
		else
		{
			cout << "Неверное значение." << endl;
		}
	}
	
	switch (mode)
	{
		case 1:
			cout << "Введите значение элемента, который нужно вставить в начало списка: ";
			InputValue(&value);
			InsertElementInBegin(list, value);
			break;
		case 2:
			cout << "Введите значение элемента, который нужно вставить в конец списка: ";
			InputValue(&value);
			AddElement(list, value);
			break;
		case 3:
			while (true)
			{
				cout << "Введите индекс элемента, после которого нужно вставить новый элемент: ";
				InputValue(&index);
				if (index >= 0 && index < list->Length)
				{
					break;
				}
				else
				{
					cout << "Неверное значение. Индекс должен быть " 
						<< "в пределах от 0 до длины списка." << endl;
				}
			}
			cout << "Введите значение элемента, который нужно вставить после " 
				<< index << " элемента списка: ";
			InputValue(&value);
			InsertElementAfterCertainElement(list, index, value);
			break;
		case 4:
			while (true)
			{
				cout << "Введите индекс элемента, перед которым нужно вставить новый элемент: ";
				InputValue(&index);
				if (index >= 0 && index < list->Length)
				{
					break;
				}
				else
				{
					cout << "Неверное значение. Индекс должен быть "
						<< "в пределах от 0 до длины списка." << endl;
				}
			}
			cout << "Введите значение элемента, который нужно вставить перед " 
				<< index << " элементом списка: ";
			InputValue(&value);
			InsertElementBeforeCertainElement(list, index, value);
			break;
		default:
			cout << "Неверное значение." << endl;
			break;
	}
}
		

int main()
{
	setlocale(LC_ALL, "Russian");
	List* list = new List;

	while (true)
	{
		cout << "\nТекущий список:\n";
		PrintList(list);
		cout << "\n" << endl;
		cout << "Функции для работы с двусвязного списка:\n";
		cout << "\n1. Создание списка." << endl
			<< "2. Удаление элемента." << endl
			<< "3. Вставка элемента в список." << endl
			<< "4. Сортировка списка." << endl
			<< "5. Линейный поиск." << endl
			<< "0. Выход.\n" << endl;
		int key;

		InputValue(&key);

		switch (key)
		{
		case 1:
			CreateListInMenu(list);
			break;
		case 2:
			if (list->Length == 0)
			{
				cout << "Невозможно удалить элемент. Список не существует." << endl;
				break;
			}
			cout << "Введите индекс элемента, который хотите удалить: ";
			int index;
			InputValue(&index);
			RemoveElement(list, index);
			break;
		case 3:
			if (list->Length == 0)
			{
				cout << "Невозможно вставить элемент. Список не существует." << endl;
				break;
			}
			ChoiceInsertMode(list);
			break;
		case 4:
			if (list->Length == 0)
			{
				cout << "Невозможно отсортировать список, так как он не существует." << endl;
				break;
			}
			SortList(list);
			break;
		case 5:
			if (list->Length == 0)
			{
				cout << "Невозможно найти элемент. Список не существует." << endl;
				break;
			}
			cout << "Введите значение элемента, который хотите найти: ";
			int value;
			InputValue(&value);
			if (LinearSearch(list, value) != -1)
			{
				cout << "Элемент списка найден под индексом " 
					<< LinearSearch(list, value) << "." << endl;
			}
			else
			{
				cout << "Элемент списка не найден." << endl;
			}
			break;
		case 0:
			exit(0);
		default:
			cout << "Неверное значение." << endl;
			break;
		}
	}

	delete list;
}