#include "Menu.h"
#include "BinaryTree.h"
#include "Treap.h"
#include <iostream>

using namespace std;

int InputValue(string outputString)
{
	if (outputString != "")
	{
		cout << outputString << endl;
	}

	int value;
	while (true)
	{
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Произошла ошибка. Попробуйте снова" << endl;
			continue;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (cin.gcount() > 1)
		{
			cout << "Произошла ошибка. Попробуйте снова" << endl;
			continue;
		}

		break;
	}

	system("cls");
	return value;
}

bool CheckElement(int value, TreapElement* tree)
{
	return SearchElementByValue(tree, value);
}

void PrintBinaryTree(BinaryTreeElement* current, int level)
{
	if (current)
	{
		PrintBinaryTree(current->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "   ";
		}
		cout << current->Data << endl;
		PrintBinaryTree(current->Left, level + 1);
	}
}


void MenuBinaryTree()
{
	BinaryTree* binaryTree = new BinaryTree();
	cout << "Функции для работы с СД \"Бинарное дерево\":" << endl;
	while (true)
	{
		cout << "\n1) Добавить элемент" << endl;
		cout << "2) Удалить элемент" << endl;
		cout << "3) Найти элемент по значению" << endl;
		cout << "4) Найти максимальный элемент" << endl;
		cout << "5) Найти минимальный элемент" << endl;
		cout << "6) Показать дерево" << endl;
		cout << "0) Выход в меню\n" << endl;
		cout << "\nВыбор: ";
		int key = InputValue("");
		switch (key)
		{
		case 1:
		{
			int value = InputValue("Введите значение элемента, который нужно добавить в дерево: ");
			BinaryTreeElement* element = CreateElement(value);
			InsertElement(binaryTree, element);
			cout << "Элемент добавлен" << endl;
			break;
		}
		case 2:
		{
			int value = InputValue("Введите значение элемента, который нужно удалить из дерева: ");
			binaryTree->Root = DeleteElement(binaryTree->Root, value);
			break;
		}
		case 3:
		{
			int value = InputValue("Введите значение элемента, который нужно найти в дереве: ");
			BinaryTreeElement* element = SearchElementByValue(binaryTree->Root, value);
			if (!element)
			{
				cout << "Элемент не найден" << endl;

			}
			else
			{
				cout << "Элемент найден" << endl;
			}
			break;
		}
		case 4:
		{
			if (!binaryTree->Root)
			{
				cout << "Дерево пустое, сначала нужно добавить элементы" << endl;
				break;
			}
			BinaryTreeElement* maxElement = SearchMaxElement(binaryTree->Root);
			cout << "Максимальный элемент = " << maxElement->Data << endl;
			break;
		}
		case 5:
		{
			if (!binaryTree->Root)
			{
				cout << "Дерево пустое, сначала нужно добавить элементы" << endl;
				break;
			}
			BinaryTreeElement* minElement = SearchMinElement(binaryTree->Root);
			cout << "Минимальный элемент = " << minElement->Data << endl;
			break;
		}
		case 6:
			if (!binaryTree->Root)
			{
				cout << "Дерево пустое, сначала нужно добавить элементы" << endl;
				break;
			}
			PrintBinaryTree(binaryTree->Root, 0);
			break;
		case 0:
			DeleteBinaryTree(binaryTree->Root);
			return;
		default:
			cout << "Неверный ввод, повторите." << endl;
			break;
		}
	}
}

void PrintTreap(TreapElement* current, int level)
{
	if (current)
	{
		PrintTreap(current->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "   ";
		}
		cout << current->Data << " : " << current->Priority << endl;
		PrintTreap(current->Left, level + 1);
	}
}

void MenuTreap()
{
	Treap* treap = new Treap();
	cout << "Функции для работы с СД \"Декартово дерево\":" << endl;
	while (true)
	{
		cout << "\n1) Вставить элемент в дерево оптимизированным алгоритмом" << endl;
		cout << "2) Вставить элемент в дерево НЕ оптимизированным алгоритмом" << endl;
		cout << "3) Удалить элемент из дерева оптимизированным алгоритмом" << endl;
		cout << "4) Удалить элемент из дерева НЕ оптимизированным алгоритмом" << endl;
		cout << "5) Поиск элемента" << endl;
		cout << "6) Показать дерево" << endl;
		cout << "0) Выход в меню\n" << endl;
		cout << "\nВыбор: ";
		int key = InputValue("");
		switch (key)
		{
		case 1:
		{
			int value = InputValue("Введите значение: ");
			if (treap->Root)
			{
				if (CheckElement(value, treap->Root))
				{
					cout << "Элемент со значением " << value << " уже существует." << endl;
					break;
				}
			}
			InsertOpt(value, rand() % treap->MaxPriority, treap->Root);
			break;
		}
		case 2:
		{
			int value = InputValue("Введите значение: ");
			if (treap->Root)
			{
				if (CheckElement(value, treap->Root))
				{
					cout << "Элемент со значением " << value << " уже существует." << endl;
					break;
				}
			}
			InsertNotOpt(treap->Root, value);
			break;
		}
		case 3:
		{
			int value = InputValue("Введите значение: ");
			DeleteOpt(value, treap->Root);
			break;
		}
		case 4:
		{
			int value = InputValue("Введите значение: ");
			DeleteNotOpt(treap->Root, value);
			break;
		}
		case 5:
		{
			int value = InputValue("Введите значение: ");
			TreapElement* element = SearchElementByValue(treap->Root, value);
			if (!element)
			{
				cout << "Такого элемента нет" << endl;

			}
			else
			{
				cout << "Элемент найден" << endl;
			}
			break;
		}
		case 6:
			PrintTreap(treap->Root, 0);
			break;
		case 0:
			DeleteTreap(treap->Root);
			return;
		default:
			cout << "Введено неверное значение. Попробуйте снова" << endl;
			break;
		}
	}
}

void Menu()
{
	cout << "Выберите, с какой структурой данных нужно работать:" << endl;
	while (true)
	{
		cout << "\n1) Бинарное дерево" << endl;
		cout << "2) Декартово дерево" << endl;
		cout << "0) Выход" << endl;
		cout << "\nВыбор: ";

		int key = InputValue("");
		switch (key)
		{
		case 1:
			MenuBinaryTree();
			break;
		case 2:
			MenuTreap();
			break;
		case 0:
			return;
		default:
			cout << "Введено неверное значение. Попробуйте снова" << endl;
			break;
		}
	}
}


