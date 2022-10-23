#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

struct cashReg
{
	int num; //����� �����
	int code; //��� ������
	int sum; //���������� ������
	float price; //���� ������
	float discount; //���������� ������ �� �����
	float disc_price; //���� � ������ ������
};

void createF(string name); //�������� � ���������� ����� � ����������
void createRandF(string name); //�������� � ���������� ����� ��������
void txtToBin(string name, string nameBin); //�������������� ���������� ����� � ��������
void binToTxt(string name, string nameBin);
cashReg getByNum(string name, int num);
void printBin(string name);
void delByKey(string name, int key, cashReg x);
cashReg getLast(string name);

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "rus");
	short problem;
	bool flag = true;
	string fileName, s, fileName2;
	int num, typeCreate, key;
	cashReg x;
	while (flag)
	{
		system("cls");
		cout << "������������ ������ �2 ����-06-21 �������� �.�. ������� 30" << "\n\n"
			"����\n"
			"1) �������� ���������� ����� ��������� ASCII.\n"
			"2) �������������� �������� ������ �� ���������� ����� � �������� ����.\n"
			"3) �������������� ������ �� ��������� ����� � ���������.\n"
			"4) ����� ���� ������� ��������� �����.\n"
			"5) ������ � ������ �� �� ����������� ������ � �����.\n"
			"6) �������� ������ � �������� ��������� �����.\n"
			"7) ������ � ������ �� �� ����������� ������ � �����.\n";
		cout << "��� �����: ";
		cin >> problem;
		switch (problem) {
		case 1:
		{
			cout << "������� ��� ���������� �����: ";
			cin >> fileName;
			cout << "��� ���������� � ���������� ������� 0, ����� (���������� �������) ����� ������ �����: ";
			cin >> typeCreate;
			if (typeCreate == 0) createF(fileName);
			else createRandF(fileName);
			system("pause");
			break;
		}
		case 2:
		{
			cout << "������� ��� ��������� �����: ";
			cin >> fileName2;
			txtToBin(fileName, fileName2);
			system("pause");
			break;
		}
		case 3:
		{
			binToTxt(fileName, fileName2);
			system("pause");
			break;
		}
		case 4:
		{
			printBin(fileName2);
			system("pause");
			break;
		}
		case 5:
		{
			cout << "������� ���������� ����� ������ � �����: ";
			cin >> num;
			x = getByNum(fileName2, num);
			if (x.num == NULL)
			{
				cout << x.num << '\n';
				cout << x.code << '\n';
				cout << x.sum << '\n';
				cout << x.price << '\n';
				cout << x.discount << '\n';
				cout << x.disc_price << '\n';
			}
			else cerr << "������ ������ � ����� ���\n";
			system("pause");
			break;
		}
		case 6:
		{
			cout << "������� �������� �����: ";
			cin >> key;
			delByKey(fileName2, key, getLast(fileName2));
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

void createF(string name) {
	int structs;
	cout << "������� ���������� �������� � �����: ";
	cin >> structs;
	cout << "������� ���������� �����: \n";
	cashReg s;
	ofstream f(name);
	cin.ignore();
	for (int i = 0; i < structs; i++) {
		cout << "��������� 1:" << "\n����� �����: ";
		cin >> s.num;
		cout << "��� �������: ";
		cin >> s.code;
		cout << "���������� �������: ";
		cin >> s.sum;
		cout << "���� �������: ";
		cin >> s.price;
		cout << "���������� ������ �� ������: ";
		cin >> s.discount;
		s.disc_price = s.price - s.price * (s.discount / 100);
		f << s.num << '\n';
		f << s.code << '\n';
		f << s.sum << '\n';
		f << s.price << '\n';
		f << s.discount << '\n';
		f << s.disc_price << '\n';
	}
	f.close();
}

void createRandF(string name) {
	int structs = 2 + (rand() % 3);
	cashReg s;
	ofstream f(name);
	for (int i = 0; i < structs; i++) {
		s.num = 1 + (rand() % 3);
		s.code = 1 + (rand() % 1000);
		s.sum = 1 + (rand() % 100);
		s.price = 1 + (rand() % 1000);
		s.discount = 1 + (rand() % 100);
		s.disc_price = s.price - s.price * (s.discount / 100);
		f << s.num << '\n';
		f << s.code << '\n';
		f << s.sum << '\n';
		f << s.price << '\n';
		f << s.discount << '\n';
		f << s.disc_price << '\n';
	}
	f.close();
}

void txtToBin(string name, string nameBin)
{
	ifstream ft;
	ofstream fb;
	ft.open(name, ios::in);
	if (!ft) cout << "���� �� ������\n";
	fb.open(nameBin, ios::out | ios::binary | ios::trunc);
	while (!ft.eof())
	{
		cashReg newS;
		ft >> newS.num;
		ft >> newS.code;
		ft >> newS.sum;
		ft >> newS.price;
		ft >> newS.discount;
		ft >> newS.disc_price;
		ft.get();
		fb.write((char*)&newS, sizeof(cashReg));
	}
	ft.close();
	fb.close();
}

void binToTxt(string name, string nameBin) {
	ofstream ft(name);
	ifstream fb(nameBin);
	ft.open(name, ios::out | ios::trunc);
	if (!ft) cout << "���� �� ������\n";
	fb.open(nameBin, ios::in | ios::binary);
	if (fb.good())
	{
		cashReg newS;
		fb.read((char*)&newS, sizeof(cashReg));
		ft << newS.num << '\n';
		ft << newS.code << '\n';
		ft << newS.sum << '\n';
		ft << newS.price << '\n';
		ft << newS.discount << '\n';
		ft << newS.disc_price << '\n';
		while (!fb.eof())
		{
			ft << newS.num << '\n';
			ft << newS.code << '\n';
			ft << newS.sum << '\n';
			ft << newS.price << '\n';
			ft << newS.discount << '\n';
			ft << newS.disc_price << '\n';
			fb.read((char*)&newS, sizeof(cashReg));
		}
	}
	ft.close();
	fb.close();
}

void printBin(string name)
{
	ifstream fb;
	fb.open(name, ios::in | ios::binary);
	if (!fb) cout << "���� �� ������\n";
	cashReg x;
	fb.read((char*)&x, sizeof(cashReg));
	while (!fb.eof())
	{
		cout << x.num << '\n';
		cout << x.code << '\n';
		cout << x.sum << '\n';
		cout << x.price << '\n';
		cout << x.discount << '\n';
		cout << x.disc_price << '\n';
		fb.read((char*)&x, sizeof(cashReg));
	}
	fb.close();
}

cashReg getByNum(string name, int num) {
	ifstream fb;
	fb.open(name, ios::in | ios::binary);
	if (!fb) cout << "���� �� ������\n";
	fb.seekg((num - 1) * sizeof(cashReg), ios::beg);
	cashReg x;
	fb.read((char*)&x, sizeof(cashReg));
	fb.close();
	return x;
}

void delByKey(string name, int key, cashReg x) {
	fstream fb;
	cashReg y;
	int pos;
	bool flag = false;
	fb.open(name, ios::in | ios::out | ios::binary);
	if (!fb) cout << "���� �� ������\n";
	fb.read((char*)&y, sizeof(cashReg));
	int i = 0;
	while (!fb.eof())
	{
		if (y.num == key)
		{
			fb.seekg(-1 * sizeof(cashReg), ios::cur);
			fb.write((char*)&x, sizeof(cashReg));
			flag = true;
			break;
		}
		else
		{
			i++;
			fb.read((char*)&y, sizeof(cashReg));
		}
	}
	if (flag == false) cout << "������ ������ � ����� ���\n";
	fb.close();
}

cashReg getLast(string name)
{
	fstream fb;
	cashReg x;
	fb.open(name, ios::in | ios::binary);
	if (!fb) cout << "���� �� ������\n";
	fb.seekg(-1 * sizeof(cashReg), ios::end);
	fb.read((char*)&x, sizeof(cashReg));
	fb.close();
	return (x);
}