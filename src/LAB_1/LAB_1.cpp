#include <iostream>
#include "DynamicArray.h"

using namespace std;

bool ArrayIsSorted = false;
bool ArrayIsCreated = false;


void InputValue(int* value)
{
	cout << ": ";
	cin >> *value;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void CreateArrayFromMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsCreated == false)
	{
		CreateArray(dynamicArray);
		ArrayIsCreated = true;
	}
	else
	{
		cout << "Массив уже создан" << endl;
		return;
	}

	int flag = true;
	int count;
	cout << "Введите количество элементов массива" << endl;

	while (flag)
	{
		InputValue(&count);

		if (count <= 0)
		{
			cout << "Количество элементов в массиве должно быть больше 0"
				<< " Попробуйте снова" << endl;
			continue;
		}

		flag = false;
	}

	flag = true;
	cout << "Выберите:" << endl;
	cout << "1. Создать массив со случайными значениями" << endl;
	cout << "2. Создать массив со своими значениями" << endl;
	while (flag)
	{
		int key;

		InputValue(&key);

		switch (key)
		{
		case 1:
			GetArrayRandom(dynamicArray, count);
			flag = false;
			break;
		case 2:
			GetArrayHandmade(dynamicArray, count);
			flag = false;
			break;
		default:
			cout << "Введено неверное значение. Попробуйте снова";
			break;
		}

		cout << endl;
	}
}

void AddElementFromMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsCreated == false)
	{
		cout << "Массив не создан" << endl;
		return;
	}

	int value;
	int index;
	cout << "Введите число" << endl;
	InputValue(&value);

	AddElement(dynamicArray, value);
	ArrayIsSorted = false;
}

void ShowArrayFromMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsCreated == false)
	{
		cout << "Массив не создан" << endl;
		return;
	}

	ShowArray(dynamicArray);
}

void RemoveElementFromMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsCreated == false)
	{
		cout << "Массив не создан" << endl;
		return;
	}

	int index;

	while (true)
	{
		cout << "Введите индекс" << endl;
		InputValue(&index);

		if (index < 0)
		{
			cout << "Индекс должен быть больше или равен нулю" << endl;
			continue;
		}
		if (index >= dynamicArray->Length)
		{
			cout << "Индекс должен быть меньше длины массива" << endl;
			continue;
		}

		break;
	}

	RemoveElement(dynamicArray, index);

	if (dynamicArray->Length == 0)
	{
		ArrayIsCreated = false;
	}
}

void InsertELementFromMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsCreated == false)
	{
		cout << "Массив не создан" << endl;
		return;
	}

	int value;
	int index;
	int flag = true;
	cout << "Введите число" << endl;
	InputValue(&value);

	cout << "Выберите:" << endl;
	cout << "1. Вставить в начало" << endl;
	cout << "2. Вставить после определенного элемента" << endl;
	cout << "3. Вставить в конец" << endl;
	while (flag)
	{
		int key;

		InputValue(&key);

		switch (key)
		{
		case 1:
			index = 0;
			InsertElement(dynamicArray, value, index);
			ArrayIsSorted = false;
			flag = false;
			break;
		case 2:
			cout << "Введите индекс" << endl;
			InputValue(&index);
			index++;

			if (index < 0)
			{
				cout << "Индекс должен быть больше или равен нулю" << endl;
				break;
			}

			if (index > dynamicArray->Length)
			{
				cout << "Нельзя добавить элемент на это место" << endl;
				break;
			}

			InsertElement(dynamicArray, value, index);
			ArrayIsSorted = false;
			flag = false;
			break;
		case 3:
			index = dynamicArray->Length;
			InsertElement(dynamicArray, value, index);
			ArrayIsSorted = false;
			flag = false;
			break;
		default:
			cout << "Введено неверное значение. Попробуйте снова";
			break;
		}

		cout << endl;
	}
}

void SortArrayFromMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsCreated == false)
	{
		cout << "Массив не создан" << endl;
		return;
	}

	SortArray(dynamicArray);
	ArrayIsSorted = true;
}

void LinearSearchFromMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsCreated == false)
	{
		cout << "Массив не создан" << endl;
		return;
	}

	int value;
	cout << "Введите число" << endl;
	InputValue(&value);
	LinearSearch(dynamicArray, value);
}

void BinarySearchFromMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsCreated == false)
	{
		cout << "Массив не создан" << endl;
		return;
	}
	if (ArrayIsSorted == false)
	{
		cout << "Массив не отсортирован" << endl;
		return;
	}

	int value;
	cout << "Введите число" << endl;
	InputValue(&value);
	BinarySearch(dynamicArray, value);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	DynamicArray* dynamicArray = new DynamicArray;

	bool flag = true;

	cout << "\tДобро пожаловать!" << endl;
	cout << "Выберите функцию из списка ниже" << endl;

	while (flag)
	{
		cout << "1. Создать массив" << endl;;
		cout << "2. Добавить элемент в массив" << endl;
		cout << "3. Удалить элемент" << endl;
		cout << "4. Вставить элемент" << endl;
		cout << "5. Показать массив" << endl;
		cout << "6. Отсортировать массив" << endl;
		cout << "7. Линейный поиск" << endl;
		cout << "8. Бинарный поиск" << endl;
		cout << "9. Выйти" << endl;

		int key;

		InputValue(&key);

		switch (key)
		{
		case 1:
			CreateArrayFromMenu(dynamicArray);
			break;
		case 2:
			AddElementFromMenu(dynamicArray);
			break;
		case 3:
			RemoveElementFromMenu(dynamicArray);
			break;
		case 4:
			InsertELementFromMenu(dynamicArray);
			break;
		case 5:
			ShowArrayFromMenu(dynamicArray);
			break;
		case 6:
			SortArrayFromMenu(dynamicArray);
			break;
		case 7:
			LinearSearchFromMenu(dynamicArray);
			break;
		case 8:
			BinarySearchFromMenu(dynamicArray);
			break;
		case 9:
			flag = false;
			break;
		default:
			cout << "Введено неверное значение. Попробуйте снова" << endl;
			break;
		}
	}

	delete[] dynamicArray->Array;
	delete dynamicArray;
}