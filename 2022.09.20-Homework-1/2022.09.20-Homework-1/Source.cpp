#include <iostream>

using namespace std;

class Locked
{
	friend struct Key;
	int a;
	void print()
	{
		cout << this->a << endl;
	}
};
struct Key
{
	void print(Locked t)
	{
		void (Locked:: * adress)() = &Locked::print;
		(t.*adress)();
	}
	void swapper(Locked& t, int a)
	{
		t.a = a;
	}
};

class Min {
	long double a; //8
	long long b; //8
	float c; //4
	int d; //4
	unsigned char e; //1
	short f; //2
	bool g; //1
	char h; //1
	/* 8+8+4+4+1+2+1+1=29 > 24 => min size=32
	1+2+1+1=5, ������������ �� 3 ����� */
};

class Max {
	char a; //1
	long long g; //8
	bool b; //1
	long double h; //8
	unsigned char d; //1
	int e; //4
	short c; //2
	float f; //4
	/* 8*8=64 >= max size - �����������, ���� �� ������ ��� �������� �� 8 ����
	��� ����� � �������� 1 ������������ �� 7 ���� �������� ������ ���� ������ ���������� ���� 8 - �������� ��������� 2 ����
	��� ���������� ����� ����� ���������� ��� ������������ � 5 ����.
	1+7 + 8 + 1+7 + 8 + 1+4+2+1 + 4+4 = 48 - ������������ �� 19 ����*/
};

int main() {

	cout << sizeof(Min) << ' ' << sizeof(Max) << endl;

	Locked test;
	Key tost;

	tost.swapper(test, 228);
	tost.print(test);

	return EXIT_SUCCESS;
};
