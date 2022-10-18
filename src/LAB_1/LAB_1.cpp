#include <iostream>
#include "DynamicArray.h"

using namespace std;

bool ArrayIsSorted = false;
bool ArrayIsExists = false;


void InputValueInMenu(int* value)
{
	cin >> *value;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void CreateArrayInMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsExists == false)
	{
		CreateArray(dynamicArray);
		ArrayIsExists = true;
	}
	else
	{
		cout << "Массив уже существует" << endl;
		return;
	}

	int flag = true;
	int count;
	cout << "Количество элементов массива = ";

	while (flag)
	{
		InputValueInMenu(&count);

		if (count <= 0)
		{
			cout << "Количество элементов в массиве не должно быть меньше 1." << endl;
			continue;
		}

		flag = false;
	}

	flag = true;
	cout << "\nВыберите:" << endl;
	cout << "1. Массив со случайными значениями" << endl;
	cout << "2. Ввести свои значения для элементов массива" << endl;

	while (flag)
	{
		int key;
		InputValueInMenu(&key);

		switch (key)
		{
			case 1:
				GetRandomArray(dynamicArray, count);
				flag = false;
				break;
			case 2:
				GetArrayByUser(dynamicArray, count);
				flag = false;
				break;
			default:
				cout << "Введено неверное значение. Попробуйте снова";
				break;
		}
	}
}

void AddElementInMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsExists == false)
	{
		cout << "Массив не существует, сначала нужно создать массив." << endl;
		return;
	}

	int value;
	int index;
	cout << "Значение нового элемента = ";
	InputValueInMenu(&value);
	AddElement(dynamicArray, value);
	ArrayIsSorted = false;
}

void ShowArrayInMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsExists == false)
	{
		cout << "Массив не существует, сначала нужно создать массив." << endl;
		return;
	}

	ShowArray(dynamicArray);
}

void RemoveElementInMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsExists == false)
	{
		cout << "Массив не существует, сначала нужно создать массив." << endl;
		return;
	}

	int index;

	while (true)
	{
		cout << "Индекс элемента, который нужно удалить = ";
		InputValueInMenu(&index);

		if (index < 0)
		{
			cout << "Индекс должен быть больше или равен нулю." << endl;
			continue;
		}
		if (index >= dynamicArray->Length)
		{
			cout << "Индекс должен быть меньше длины массива." << endl;
			continue;
		}

		break;
	}

	RemoveElement(dynamicArray, index);

	if (dynamicArray->Length == 0)
	{
		ArrayIsExists = false;
	}
}

void InsertELementInMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsExists == false)
	{
		cout << "Массив не существует, сначала нужно создать массив." << endl;
		return;
	}

	int value;
	int index;
	int flag = true;

	cout << "Значение нового элемента = ";
	InputValueInMenu(&value);

	cout << "Вставить элемент:" << endl;
	cout << "1. в начало массива" << endl;
	cout << "2. после определенного элемента" << endl;
	cout << "3. в конец массива" << endl;
	while (flag)
	{
		int key;

		InputValueInMenu(&key);

		switch (key)
		{
		case 1:
			index = 0;
			InsertElement(dynamicArray, value, index);
			ArrayIsSorted = false;
			flag = false;
			break;
		case 2:
			cout << "Индекс массива, после которого нужно расположить новый элемент = ";
			InputValueInMenu(&index);
			index++;

			if (index < 0)
			{
				cout << "Индекс массива должен быть больше или равен 0." << endl;
				break;
			}

			if (index > dynamicArray->Length)
			{
				cout << "Невозможно поставить элемент на это место." << index << endl;
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
			cout << "Неверное значение.";
			break;
		}
	}
}

void SortArrayInMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsExists == false)
	{
		cout << "Массив не существует, сначала нужно создать массив." << endl;
		return;
	}

	SortArray(dynamicArray);
	ArrayIsSorted = true;
}

void LinearSearchInMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsExists == false)
	{
		cout << "Массив не существует, сначала нужно создать массив." << endl;
		return;
	}

	int value;
	cout << "Значение элемента, который нужно найти = ";
	InputValueInMenu(&value);
	LinearSearch(dynamicArray, value);
}

void BinarySearchInMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsExists == false)
	{
		cout << "Массив не существует, сначала нужно создать массив." << endl;
		return;
	}
	if (ArrayIsSorted == false)
	{
		cout << "Массив еще не отсортирован." << endl;
		return;
	}

	int value;
	cout << "Значение элемента, который нужно найти = ";
	InputValueInMenu(&value);
	BinarySearch(dynamicArray, value);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	DynamicArray* dynamicArray = new DynamicArray;

	bool isInWork = true;

	cout << "Функции для работы с массивом:" << endl;

	while (isInWork)
	{
		cout << "\n1. Создание массива." << endl;;
		cout << "2. Вывод массива на экран." << endl;
		cout << "3. Удаление элемента." << endl;
		cout << "4. Вставка элемента." << endl;
		cout << "5. Добавление элемента в массив." << endl;
		cout << "6. Сортировка массива." << endl;
		cout << "7. Линейный поиск." << endl;
		cout << "8. Бинарный поиск." << endl;
		cout << "9. Выход.\n" << endl;

		int key;
		InputValueInMenu(&key);

		switch (key)
		{
			case 1:
				CreateArrayInMenu(dynamicArray);
				break;
			case 2:
				ShowArrayInMenu(dynamicArray);
				break;
			case 3:
				RemoveElementInMenu(dynamicArray);
				break;
			case 4:
				InsertELementInMenu(dynamicArray);
				break;
			case 5:
				AddElementInMenu(dynamicArray);
				break;
			case 6:
				SortArrayInMenu(dynamicArray);
				break;
			case 7:
				LinearSearchInMenu(dynamicArray);
				break;
			case 8:
				BinarySearchInMenu(dynamicArray);
				break;
			case 9:
				isInWork = false;
				break;
			default:
				cout << "Неверное значение." << endl;
				break;
		}
	}

	delete[] dynamicArray->Array;
	delete dynamicArray;
}