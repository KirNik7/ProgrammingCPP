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

/// <summary>
/// Функция, которая выполняет задачу для задания 1.1.4.1.
/// </summary>
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

void Task1142()
{
	int a[10] = { 1, 2, 7, -1, 5, 3, -1, 7, 1, 6 };
	cout << "Size of int type: " << sizeof(int) << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "Address of a[" << i << "]: " << &a[i] << endl;
	}

	cout << endl;
	cout << "Size of double type: " << sizeof(double) << endl;
	double b[10] = { 1.0, 2.0, 7.0, -1.0, 5.0, 3.5, -1.8, 7.2, 1.9, 6.2};
	for (int i = 0; i < 10; i++)
	{
		cout << "Address of b[" << i << "]: " << &b[i] << endl;
	}
}

void Task1143()
{
	int a = 5;
	int& b = a;

	cout << "Address of a: " << &a << endl;
	cout << "Address of b: " << &b << endl;

	cout << endl;
	b = 7;
	cout << "Value of a: " << a << endl;
}

void Foo(double a)
{
	cout << "Address of a in Foo(): " << &a << endl;
	cout << "Value of a in Foo(): " << a << endl;

	a = 15.0;
	cout << "New value of a in Foo(): " << a << endl;
}

void Task1144()
{
	double a = 5.0;
	cout << "Address of a in main(): " << &a << endl;
	cout << "Value of a in main(): " << a << endl;
	cout << endl;

	Foo(a);

	cout << endl;
	cout << "Value of a in main(): " << a << endl;
}

void Foo2(double& a)
{
	cout << "Address of a in Foo(): " << &a << endl;
	cout << "Value of a in Foo(): " << a << endl;
	a = 15.0;
	cout << "New value of a in Foo(): " << a << endl;
}

void Task1145()
{
	double a = 5.0;
	cout << "Address of a in main(): " << &a << endl;
	cout << "Value of a in main(): " << a << endl;
	cout << endl;
	Foo2(a);
	cout << endl;
	cout << "Value of a in main(): " << a << endl;
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
		cout << " 1) 1.1.1.1   2) 1.1.1.2\n";
		cout << " 3) 1.1.2.1   4) 1.1.2.2\n";
		cout << " 5) 1.1.2.3   6) 1.1.3.1\n";
		cout << " 7) 1.1.3.2   8) 1.1.3.3\n";
		cout << " 9) 1.1.3.4  10) 1.1.4.1\n";
		cout << "11) 1.1.4.2  12) 1.1.4.3\n";
		cout << "13) 1.1.4.4  14) 1.1.4.5\n";
		cout << "15) 1.1.4.6  16) 1.1.4.7\n";
		cout << "17) 1.1.4.8  18) 1.1.5.1\n";
		cout << "19) 1.1.5.2  20) 1.1.5.3\n";
		cout << "21) 1.1.5.4  22) 1.1.5.5\n";
		cout << "23) 1.1.5.6  24) 1.1.5.7\n";
		cout << "25) 1.1.5.8\n";

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
		case 11:
			cout << "\nTask 1.1.4.2:\n" << endl;
			Task1142();
			break;
		case 12:
			cout << "\nTask 1.1.4.3:\n" << endl;
			Task1143();
			break;
		case 13:
			cout << "\nTask 1.1.4.4:\n" << endl;
			Task1144();
			break;
		case 14:
			cout << "\nTask 1.1.4.5:\n" << endl;
			Task1145();
			break;
		case 15:
			cout << "\nTask 1.1.4.6:\n" << endl;
			//Task1146();
			break;
		case 16:
			cout << "\nTask 1.1.4.7:\n" << endl;
			//Task1147();
			break;
		case 17:
			cout << "\nTask 1.1.4.8:\n" << endl;
			//Task1148();
			break;
		case 18:
			cout << "\nTask 1.1.5.1:\n" << endl;
			//Task1151();
			break;
		case 19:
			cout << "\nTask 1.1.5.2:\n" << endl;
			//Task1152();
			break;
		case 20:
			cout << "\nTask 1.1.5.3:\n" << endl;
			//Task1153();
			break;
		case 21:
			cout << "\nTask 1.1.5.4:\n" << endl;
			//Task1154();
			break;
		case 22:
			cout << "\nTask 1.1.5.5:\n" << endl;
			//Task1155();
			break;
		case 23:
			cout << "\nTask 1.1.5.6:\n" << endl;
			//Task1156();
			break;
		case 24:
			cout << "\nTask 1.1.5.7:\n" << endl;
			//Task1157();
			break;
		case 25:
			cout << "\nTask 1.1.5.8:\n" << endl;
			//Task1158();
			break;
		default:
			cout << "\nIncorrect input\n" << endl;
		}
		cout << "\n";
	}
}