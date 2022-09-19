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
/// Функция, которую требуется написать по заданию 1.1.3.1.
/// </summary>
/// <param name="base">Значение, которое возводится в степень exponent.</param>
/// <param name="exponent">Степень, в которую возводится значение base.</param>
/// <returns>Возвращает значение, равное возведенному значению base в степень exponent.</returns>
double GetPower(double base, int exponent)
{
	return pow(base, exponent);
}

/// <summary>
/// Функция, которая выполняет задачу для задания 1.1.3.2.
/// </summary>
void Task1132()
{
	cout << "2.0 ^ 5 = " << GetPower(2.0, 5) << endl;
	cout << "3.0 ^ 4 = " << GetPower(3.0, 4) << endl;
	cout << "-2.0 ^ 5 = " << GetPower(-2.0, 5) << endl;
}

/// <summary>
/// Функция, которую требуется написать по заданию 1.1.3.3.
/// </summary>
/// <param name="base">Значение, которое возводится в степень exponent.</param>
/// <param name="exponent">Степень, в которую возводится значение base.</param>
void DemoGetPower(double base, int exponent)
{
	cout << base << " ^ " << exponent << " = " << GetPower(base, exponent) << endl;
}

/// <summary>
/// Функция, которая выполняет задачу для задания 1.1.3.3.
/// </summary>
void Task1133()
{
	DemoGetPower(2.0, 5);
	DemoGetPower(3.0, 4);
	DemoGetPower(-2.0, 5);
}

/// <summary>
/// Функция, которую требуется написать по заданию 1.1.3.4.
/// </summary>
/// <param name="value">Значение, которое нужно округлить до десятков.</param>
void RoundToTens(int& value)
{
	if (value % 10 < 5)
	{
		value = value / 10 * 10;
	}
	else
	{
		value = ((value / 10) + 1) * 10;
	}
}

/// <summary>
/// Функция, которая выполняет задачу для задания 1.1.3.4.
/// </summary>
void Task1134()
{
	int a = 14;
	cout << "For " << a << " rounded value is ";
	RoundToTens(a);
	cout << a << "\n";

	a = 191;
	cout << "For " << a << " rounded value is ";
	RoundToTens(a);
	cout << a << "\n";

	a = 27;
	cout << "For " << a << " rounded value is ";
	RoundToTens(a);
	cout << a << "\n";
}

void Task1141()
{
	int a = 5;
	int b = 4;
	cout << "Address of a: " << &a << endl;
	cout << "Address of b: " << &b << endl;

	double c = 13.5;
	cout << "Address of c: " << &c << endl;

	bool d = true;
	cout << "Address of d: " << &d << endl;
}

/// <summary>
/// Основная функция программы, позволяет пользователю взаимодействовать с программой.
/// </summary>
/// <returns></returns>
int main()
{	
	int choice;

	while (true)
	{
		cout << "1) 1.1.1.1   2) 1.1.1.2\n";
		cout << "3) 1.1.2.1   4) 1.1.2.2\n";
		cout << "5) 1.1.2.3   6) 1.1.3.1\n";
		cout << "7) 1.1.3.2   8) 1.1.3.3\n";
		cout << "9) 1.1.3.4  10) 1.1.4.1\n";

		cout << "\nChoice task (\"0\" for exit): ";

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
		case 6:
			cout << "\nTask 1.1.3.1:\nPart of code:\n\n";
			cout << "double GetPower(double base, int exponent)\n";
			cout << "{\n	return pow(base, exponent);\n}\n";
			break;
		case 7:
			cout << "\nTask 1.1.3.2:\n" << endl;
			Task1132();
			break;
		case 8:
			cout << "\nTask 1.1.3.3:\n" << endl;
			Task1133();
			break;
		case 9:
			cout << "\nTask 1.1.3.4:\n" << endl;
			Task1134();
			break;
		case 10:
			cout << "\nTask 1.1.4.1:\n" << endl;
			Task1141();
			break;
		default:
			cout << "\nIncorrect input\n" << endl;
		}
		cout << "\n";
	}
}