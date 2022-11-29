#include <iostream>
#include "DynamicArray.h"
#include "Menu.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	DynamicArray* dynamicArray = new DynamicArray;
	bool isInWork = true;

	while (isInWork)
	{
		cout << "\nТекущий массив:\n";
		ArrayIsExistsInMenu(dynamicArray);
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