#include "Menu.h"
#include <iostream>
#include "Dictionary.h"

using namespace std;

int InputValue(string outputString)
{
	if (outputString != "")
	{
		cout << outputString;
	}

	int value;
	while (true)
	{
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�������� ����, ���������." << endl;
			continue;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (cin.gcount() > 1)
		{
			cout << "�������� ����, ���������." << endl;
			continue;
		}

		break;
	}

	system("cls");
	return value;
}

string InputString(string outputString)
{
	if (outputString != "")
	{
		cout << outputString;
	}
	string str;
	cin >> str;
	system("cls");
	return str;
}

void MenuDictionary()
{
	Dictionary* dictionary = new Dictionary();
	while (true)
	{
		cout << "������� ��� ������ �� ��������:\n" << endl;
		cout << "1) �������� ������� � �������" << endl;
		cout << "2) ������� ������� �� �������" << endl;
		cout << "3) ����� ������� �� �����" << endl;
		cout << "0) ����� � ����" << endl;
		int key = InputValue("\n�����: ");
		switch (key)
		{
			case 1:
			{
				string key = InputString("������� ����: ");
				string value = InputString("������� ��������: ");
				Element* element = CreateElement(key, value);
				if (!InsertElement(dictionary, element, key))
				{
					cout << "����� ������� ��� ����������" << endl;
				}
				PrintHashTable(dictionary->Table);
				cout << endl;
				break;
			}
			case 2:
			{
				string key = InputString("������� ����: ");
				if (!RemoveElement(dictionary, key))
				{
					cout << "������ �������� �� ����������" << endl;
				}
				PrintHashTable(dictionary->Table);
				cout << endl;
				break;
			}
			case 3:
			{
				string key = InputString("������� ����: ");
				string data;
				if (FindElement(dictionary, key, data))
				{
					cout << "��������� ����������: " << data << endl;
				}
				else
				{
					cout << "�� �������" << endl;
				}
				break;
			}
			case 0:
			{
				DeleteDictionary(dictionary);
				return;
			}
			default:
				cout << "�������� ����, ���������." << endl;
				break;
			}
	}
}

void MenuHashTable()
{
	HashTable* table = CreateTable(4);
	while(true)
	{
		cout << "������� ��� ������ � ���-��������:\n" << endl;
		cout << "1) �������� ������� � �������" << endl;
		cout << "2) ������� ������� �� �������" << endl;
		cout << "3) ����� ������� �� �����" << endl;
		cout << "4) ������� ���-�������" << endl;
		cout << "0) ����� � ����" << endl;
		int key = InputValue("\n�����: ");
		switch (key)
		{
			case 1:
			{
				string key = InputString("������� ����: ");
				string value = InputString("������� ��������: ");
				Element* element = CreateElement(key, value);
				int index = HashFunc(key, table->Size);
				if (!InsertElement(table, element, index))
				{
					cout << "����� ������� ��� ����������" << endl;
				}
				PrintHashTable(table);
				cout << endl;
				break;
			}
			case 2:
			{
				string key = InputString("������� ����: ");
				if (!RemoveElement(table, key))
				{
					cout << "������ �������� �� ����������" << endl;
				}
				PrintHashTable(table);
				cout << endl;
				break;
			}
			case 3:
			{
				string key = InputString("������� ����: ");
				string data;
				if (FindElement(table, key, data))
				{
					cout << "��������� ����������: " << data << endl;
				}
				else
				{
					cout << "�� �������" << endl;
				}
				break;
			}
			case 4:
			{
				PrintHashTable(table);
				cout << endl;
				break;
			}
			case 0:
			{
				DeleteTable(table);
				return;
			}
			default:
				cout << "�������� ����, ���������." << endl;
				break;
		}
	}
}

void PrintHashTable(HashTable* table)
{
	Element* current;
	for (int i = 0; i < table->Size; i++)
	{
		current = table->Array[i]->Head;

		if (current != nullptr)
		{
			cout << "[" << i << "] " <<current->Key << " : " << current->Value << endl;
			current = current->Next;

			while (current != nullptr)
			{
				cout << " >> ";
				cout << "[" << i << "] " << current->Key << " : " << current->Value << endl;
				current = current->Next;
			}
		}
		else
		{
			cout << "[" << i << "] _ : _" << endl;
		}
	}
}


void Menu()
{
	while (true)
	{
		cout << "��������, � ����� ���������� ������ ����� ��������:\n" << endl;
		cout << "1) ���-�������" << endl;
		cout << "2) �������" << endl;
		cout << "0) �����" << endl;

		int key = InputValue("\n�����: ");
		switch (key)
		{
			case 1:
				MenuHashTable();
				break;
			case 2:
				MenuDictionary();
				break;
			case 0:
				return;
			default:
				cout << "�������� ����, ���������." << endl;
				break;
		}
	}
} 