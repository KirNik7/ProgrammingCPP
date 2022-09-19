#include <iostream>
#include <cmath>

using namespace std;

/// <summary>
/// Функция, которая выполняет задачу для задания 1.1.1.1.
/// </summary>
void Task1111()
{
	double add = 1.0;
	double sum = 0.0;
	for (int i = 0; i < 10; i++)
	{
		sum += add * i;
		add *= 1.1; // 0; 1.1; 3.52; 7.513; 13.3694; 21.422; 32.0513; 45.6923; 62.841; 84.0626
	}
	cout << "Total sum is " << sum << endl;
}

/// <summary>
/// Функция, которая выполняет задачу для задания 1.1.1.2.
/// </summary>
void Task1112()
{
	double add = 1.0;
	double sum = 0.0;
	for (int i = 0; i < 1000; i++)
	{
		sum += add * i; // Поставьте условную точку останова здесь (sum = 3.2625)
		if (i % 3 == 0)
		{
			add *= 1.1;
		}
		else
		{
			add /= 3.0;
		}
	}
	cout << "Total sum is " << sum << endl;
}

/// <summary>
/// Функция, которая выполняет задачу для задания 1.1.2.1.
/// </summary>
void Task1121()
{
	const int n = 10;
	int mas[n];

	cout << "Source array is:\n";
	for (int i = 0; i < n; i++)
	{
		mas[i] = rand() % 50 - 10;
		cout << mas[i] << " ";
	}

	cout << "\nSorted array is:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mas[j] > mas[i])
			{
				swap(mas[j], mas[i]);
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	cout << "\n";

}

/// <summary>
/// Функция, которая выполняет задачу для задания 1.1.2.2.
/// </summary>
void Task1122()
{
	double searchingValue;
	int countValues = 0;
	const int n = 12;
	double mas[n];

	cout << "Source array is:\n";
	for (int i = 0; i < n; i++)
	{
		mas[i] = floor((double)rand() / (double)RAND_MAX * (1000 - -1000) + -1000)/10;
		cout << mas[i] << " ";
	}
	
	cout << "\n\nEnter searching value: ";
	cin >> searchingValue;
	for (int i = 0; i < n; i++)
	{
		if (mas[i] >= searchingValue)
		{
			countValues++;
		}
	}
	cout << "\nElements of array more than " << searchingValue << " is: " << countValues << "\n";
}

/// <summary>
/// Функция, которая выполняет задачу для задания 1.1.2.3.
/// </summary>
void Task1123()
{
	const int n = 8;
	char mas[n];

	cout << "Enter array of 8 chars\n";

	for (int i = 0; i < n; i++)
	{
		cout << "\na[" << i << "]:";
		cin >> mas[i];
	}

	cout << "\nYour array is:\n";

	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}

	cout << "\n\nAll letters in your array:\n";

	for (int i = 0; i < n; i++)
	{
		if (mas[i] >= 'a' && mas[i] <= 'z')
		{
			cout << mas[i] << " ";
		}
	}
	cout << "\n";
}

/// <summary>
/// Основная функция программы, позволяет пользователю взаимодействовать с программой.
/// </summary>
/// <returns></returns>
int main()
{
	//setlocale(LC_ALL, "russian");
	
	int choice;

	while (true)
	{
		cout << "1) 1.1.1.1  2) 1.1.1.2\n";
		cout << "3) 1.1.2.1  4) 1.1.2.2\n";
		cout << "5) 1.1.2.3  6) 1.1.3.1\n";
		cout << "Choice task (\"0\" for exit): ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			return 0;
		case 1:
			cout << "\nTask 1.1.1.1:\n" << endl;
			Task1111();
			break;
		case 2:
			cout << "\nTask 1.1.1.2:\n" << endl;
			Task1112();
			break;
		case 3:
			cout << "\nTask 1.1.2.1:\n" << endl;
			Task1121();
			break;
		case 4:
			cout << "\nTask 1.1.2.2:\n" << endl;
			Task1122();
			break;
		case 5:
			cout << "\nTask 1.1.2.3:\n" << endl;
			Task1123();
			break;
		default:
			cout << "\nIncorrect input\n" << endl;
		}
		cout << "\n";
	}
}