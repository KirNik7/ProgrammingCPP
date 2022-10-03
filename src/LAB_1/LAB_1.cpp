#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

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
				
				break;
			case 2:
				cout << "\nTask 1.1.1.2:\n" << endl;
				
				break;
			case 3:
				cout << "\nTask 1.1.2.1:\n" << endl;
				
				break;
			case 4:
				cout << "\nTask 1.1.2.2:\n" << endl;
				
				break;
			case 5:
				cout << "\nTask 1.1.2.3:\n" << endl;
				
				break;
			case 6:
				cout << "\nTask 1.1.3.1:\n" << endl;
				
				break;
			case 7:
				cout << "\nTask 1.1.3.2:\n" << endl;
				
				break;
			case 8:
				cout << "\nTask 1.1.3.3:\n" << endl;
				
				break;
			case 9:
				cout << "\nTask 1.1.3.4:\n" << endl;
				
				break;
			default:
				cout << "\nIncorrect input\n" << endl;
		}
		cout << "\n";
	}
}