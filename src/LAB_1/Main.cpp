#include <iostream>
#include "DynamicArray.h"

using namespace std;

bool ArrayIsSorted = false;
bool ArrayIsExists = false;

/// <summary>
/// Реализует функцию ввода значения в меню.
/// </summary>
/// <param name="value">Значение в меню.</param>
void InputValueInMenu(int* value)
{
	cin >> *value;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/// <summary>
/// Реализует создание массива через меню.
/// </summary>
/// <param name="dynamicArray">Динамический массив.</param>
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

	int isHaveNotCount = true;
	int count;
	cout << "Количество элементов массива = ";

	while (isHaveNotCount)
	{
		InputValueInMenu(&count);

		if (count <= 0)
		{
			cout << "Количество элементов в массиве не должно быть меньше 1." << endl;
			continue;
		}

		isHaveNotCount = false;
	}

	bool isHaveNotChoice = true;
	cout << "\nВыберите:" << endl;
	cout << "1. Массив со случайными значениями" << endl;
	cout << "2. Ввести свои значения для элементов массива" << endl;

	while (isHaveNotChoice)
	{
		int key;
		InputValueInMenu(&key);

		switch (key)
		{
			case 1:
				GetRandomArray(dynamicArray, count);
				isHaveNotChoice = false;
				break;
			case 2:
				GetArrayByUserInMenu(dynamicArray, count);
				isHaveNotChoice = false;
				break;
			default:
				cout << "Неверное значение.";
				break;
		}
	}

	cout << "\nМассив создан.\n";
}

/// <summary>
/// Реализует добавление нового элемента в динамический массив через меню.
/// </summary>
/// <param name="dynamicArray">Динамический массив.</param>
void AddElementInMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsExists == false)
	{
		cout << "Массив не существует, сначала нужно создать массив." << endl;
		return;
	}

	int value;
	cout << "Значение нового элемента = ";
	InputValueInMenu(&value);
	AddElement(dynamicArray, value);
	ArrayIsSorted = false;
	cout << "\nНовый элемент добавлен в массив.\n";
}

/// <summary>
/// Реализует удаление элемента динамического массива через меню.
/// </summary>
/// <param name="dynamicArray">Динамический массив.</param>
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

	cout << "\nУказанный элемент был удален массива.\n";
}

/// <summary>
/// Реализует вставку нового элемента в динамический массив через меню.
/// </summary>
/// <param name="dynamicArray">Динамический массив.</param>
void InsertELementInMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsExists == false)
	{
		cout << "Массив не существует, сначала нужно создать массив." << endl;
		return;
	}

	int value;
	int index;
	int isHaveNotIndex = true;

	cout << "Значение нового элемента = ";
	InputValueInMenu(&value);

	cout << "Вставить элемент:" << endl;
	cout << "1. в начало массива" << endl;
	cout << "2. после определенного элемента" << endl;
	cout << "3. в конец массива" << endl;
	while (isHaveNotIndex)
	{
		int key;

		InputValueInMenu(&key);

		switch (key)
		{
		case 1:
			index = 0;
			InsertElement(dynamicArray, value, index);
			ArrayIsSorted = false;
			isHaveNotIndex = false;
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
			isHaveNotIndex = false;
			break;
		case 3:
			index = dynamicArray->Length;
			InsertElement(dynamicArray, value, index);
			ArrayIsSorted = false;
			isHaveNotIndex = false;
			break;
		default:
			cout << "Неверное значение.";
			break;
		}
	}
	cout << "\nНовый элемент добавлен на указанное место.\n";
}

/// <summary>
/// Реализует сортировку динамического массива через меню.
/// </summary>
/// <param name="dynamicArray">Динамический массив.</param>
void SortArrayInMenu(DynamicArray* dynamicArray)
{
	if (ArrayIsExists == false)
	{
		cout << "Массив не существует, сначала нужно создать массив." << endl;
		return;
	}

	SortArray(dynamicArray);
	ArrayIsSorted = true;
	cout << "\nМассив отсортирован.\n";
}

/// <summary>
/// Реализует линейный поиск элемента в динамическом массиве через меню.
/// </summary>
/// <param name="dynamicArray">Динамический массив.</param>
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
	if (LinearSearch(dynamicArray, value) == -1)
	{
		cout << "Элемент не найден" << endl;
	}
	else
	{
		cout << "Элемент " << value << " найден по индексу " << 
			LinearSearch(dynamicArray, value) << endl;
	}
}

/// <summary>
/// Реализует бинарный поиск элемента в динамическом массиве через меню.
/// </summary>
/// <param name="dynamicArray">Динамический массив.</param>
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
	if (BinarySearch(dynamicArray, value) == -1)
	{
		cout << "Элемент не найден" << endl;
	}
	else
	{
		cout << "Элемент " << value << " найден по индексу " << 
			BinarySearch(dynamicArray, value) << endl;
	}
}

/// <summary>
/// Реализует получение пользовательских элементов динамического массива через меню.
/// </summary>
/// <param name="dynamicArray">Динамический массив.</param>
/// <param name="length">Длина динамического массива.</param>
void GetArrayByUserInMenu(DynamicArray* dynamicArray, int length)
{
	int value;
	for (int i = 0; i < length; i++)
	{
		cout << i << " элемент массива = ";
		cin >> value;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		AddElement(dynamicArray, value);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	DynamicArray* dynamicArray = new DynamicArray;

	bool isInWork = true;

	while (isInWork)
	{
		cout << "\nТекущий массив:\n";

		if (ArrayIsExists)
		{
			for (int i = 0; i < dynamicArray->Length; i++)
			{
				cout << dynamicArray->Array[i] << " ";
			}
		}
		else
		{
			cout << "Не создан.";
		}

		cout << "\n" << endl;

		cout << "Функции для работы с массивом:\n";

		cout << "\n1. Создание массива." << endl
			<< "2. Удаление элемента." << endl
			<< "3. Вставка элемента." << endl
			<< "4. Добавление элемента в массив." << endl
			<< "5. Сортировка массива." << endl
			<< "6. Линейный поиск." << endl
			<< "7. Бинарный поиск." << endl
			<< "0. Выход.\n" << endl;

		int key;
		InputValueInMenu(&key);

		switch (key)
		{
			case 1:
				CreateArrayInMenu(dynamicArray);
				break;
			case 2:
				RemoveElementInMenu(dynamicArray);
				break;
			case 3:
				InsertELementInMenu(dynamicArray);
				break;
			case 4:
				AddElementInMenu(dynamicArray);
				break;
			case 5:
				SortArrayInMenu(dynamicArray);
				break;
			case 6:
				LinearSearchInMenu(dynamicArray);
				break;
			case 7:
				BinarySearchInMenu(dynamicArray);
				break;
			case 0:
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