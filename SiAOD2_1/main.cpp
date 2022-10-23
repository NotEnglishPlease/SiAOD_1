#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int task1(int x);
int task2(int x);
int task3(int x);
int task4(int x);
int task5(int x, int n);
string toBit(unsigned int num); //���������� num � �������� �� (��� string)

int main()
{
	setlocale(LC_ALL, "rus");
	short problem;
	bool flag = true;
	int num, n;
	while (flag)
	{
		system("cls");
		cout << "������������ ������ �1 ����-06-21 �������� �.�. ������� 11" << "\n\n"
			"����\n"
			"1) � 5-��� ������ ����� � 1.\n"
			"2) 5-��, 7-�� ������ � 0.\n"
			"3) ��������� ��������� ���������� �� 32, ��������� ����������� ��������.\n"
			"4) ������� ��������� ���������� �� 32, ��������� ����������� ��������.\n"
			"5) �������� n-�� ���, ��������� ����� 1.\n";
		cout << "��� �����: ";
		cin >> problem;
		switch (problem) {
		case 1:
		{
			cout << "\n������� ���������� � 16-�� ������� ���������: ";
			cin >> hex >> num;
			cout << right << setw(32) << toBit(num) << " (��������� �����)\n";
			cout << right << setw(32) << toBit(task1(num)) << " (�������� �����)\n";
			system("pause");
			break;
		}
		case 2:
		{
			cout << "\n������� ���������� � 16-�� ������� ���������: ";
			cin >> hex >> num;
			cout << right << setw(32) << toBit(num) << " (��������� �����)\n";
			cout << right << setw(32) << toBit(task2(num)) << " (�������� �����)\n";
			system("pause");
			break;
		}
		case 3:
		{
			cout << "\n������� ���������� � 16-�� ������� ���������: ";
			cin >> hex >> num;
			cout << right << setw(32) << toBit(num) << " (��������� �����)\n";
			cout << right << setw(32) << toBit(task3(num)) << " (�������� �����)\n";
			system("pause");
			break;
		}
		case 4:
		{
			cout << "\n������� ���������� � 16-�� ������� ���������: ";
			cin >> hex >> num;
			cout << right << setw(32) << toBit(num) << " (��������� �����)\n";
			cout << right << setw(32) << toBit(task4(num)) << " (�������� �����)\n";
			system("pause");
			break;
		}
		case 5:
		{
			cout << "\n������� ���������� � 16-�� ������� ���������: ";
			cin >> hex >> num;
			cout << "\n������� n: ";
			cin >> n;
			cout << right << setw(32) << toBit(num) << " (��������� �����)\n";
			cout << right << setw(32) << toBit(task5(num, n)) << " (�������� �����)\n";
			system("pause");
			break;
		}
			break;
		default:
			cout << "��������, � �� ������ �������, ��� �� ������ �������. ���������� � ������ ���.\n";
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
	cout << right << setw(32) << toBit(mask) << " (�����)\n";
	return x | mask;
}

int task2(int x) {
	int mask = ~0b10100000;
	cout << right << setw(32) << toBit(mask) << " (�����)\n";
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
	cout << right << setw(32) << toBit(mask) << " (�����)\n";
	return x & mask;
}