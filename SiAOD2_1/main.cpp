#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int task1(int x);
int task2(int x);
int task3(int x);
int task4(int x);
int task5(int x, int n);
string toBit(unsigned int num); //возвращает num в двоичной сс (тип string)

int main()
{
	setlocale(LC_ALL, "rus");
	short problem;
	bool flag = true;
	int num, n;
	while (flag)
	{
		system("cls");
		cout << "Практическая работа №1 ИКБО-06-21 Эрднеева Н.Д. Варинат 11" << "\n\n"
			"Меню\n"
			"1) С 5-ого четыре слева в 1.\n"
			"2) 5-ый, 7-ой справа в 0.\n"
			"3) Умножение введенной переменной на 32, используя поразрядную операцию.\n"
			"4) Деление введенной переменной на 32, используя поразрядную операцию.\n"
			"5) Обнулить n-ый бит, используя маску 1.\n";
		cout << "Ваш выбор: ";
		cin >> problem;
		switch (problem) {
		case 1:
		{
			cout << "\nВведите переменную в 16-ой системе счисления: ";
			cin >> hex >> num;
			cout << right << setw(32) << toBit(num) << " (Начальное число)\n";
			cout << right << setw(32) << toBit(task1(num)) << " (Конечное число)\n";
			system("pause");
			break;
		}
		case 2:
		{
			cout << "\nВведите переменную в 16-ой системе счисления: ";
			cin >> hex >> num;
			cout << right << setw(32) << toBit(num) << " (Начальное число)\n";
			cout << right << setw(32) << toBit(task2(num)) << " (Конечное число)\n";
			system("pause");
			break;
		}
		case 3:
		{
			cout << "\nВведите переменную в 16-ой системе счисления: ";
			cin >> hex >> num;
			cout << right << setw(32) << toBit(num) << " (Начальное число)\n";
			cout << right << setw(32) << toBit(task3(num)) << " (Конечное число)\n";
			system("pause");
			break;
		}
		case 4:
		{
			cout << "\nВведите переменную в 16-ой системе счисления: ";
			cin >> hex >> num;
			cout << right << setw(32) << toBit(num) << " (Начальное число)\n";
			cout << right << setw(32) << toBit(task4(num)) << " (Конечное число)\n";
			system("pause");
			break;
		}
		case 5:
		{
			cout << "\nВведите переменную в 16-ой системе счисления: ";
			cin >> hex >> num;
			cout << "\nВведите n: ";
			cin >> n;
			cout << right << setw(32) << toBit(num) << " (Начальное число)\n";
			cout << right << setw(32) << toBit(task5(num, n)) << " (Конечное число)\n";
			system("pause");
			break;
		}
			break;
		default:
			cout << "Извините, я не совсем понимаю, что вы хотите сделать. Попробуйте в другой раз.\n";
			system("pause");
			break;
		}
	}
	return 0;
}

string toBit(unsigned int num) { 
	string bitNum = "";
	while (num != 0) {
		bitNum = to_string(num % 2) + bitNum;
		num /= 2;
	}
	return bitNum;
}

int task1(int x) {
	int mask = 0b111100000;
	cout << right << setw(32) << toBit(mask) << " (Маска)\n";
	return x | mask;
}

int task2(int x) {
	int mask = ~0b10100000;
	cout << right << setw(32) << toBit(mask) << " (Маска)\n";
	return x & mask;
}

int task3(int x) {
	x = x << 5;
	return x;
}

int task4(int x) {
	x = x >> 5;
	return x;
}

int task5(int x, int n) {
	int mask = 0b1;
	mask = ~(mask << n);
	cout << right << setw(32) << toBit(mask) << " (Маска)\n";
	return x & mask;
}