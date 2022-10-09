#include <iostream>

using namespace std;

class FieldPrint {
	int x = 0;
	int y = 0;
	int z = 0;

	void printX() {
		cout << this->x;
	};
	void printY() {
		cout << this->y;
	};
	void printZ() {
		cout << this->z;
	};
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
	1+2+1+1=5, выравнивание на 3 байта */
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
	/* 8*8=64 >= max size - достигается, если на каждый тип выделено по 8 байт
	для типов с размером 1 выравнивание на 7 байт возможно только если размер следующего типа 8 - возможго выполнить 2 раза
	для оставшихся типов любая комбинация даёт выравнивание в 5 байт.
	1+7 + 8 + 1+7 + 8 + 1+4+2+1 + 4+4 = 48 - выравнивание на 19 байт*/
};

int main() {

	cout << sizeof(Min) << ' ' << sizeof(Max) << endl;

	FieldPrint inst;

	int* a = (int*)(&inst);
	cout << *a << endl;
	*a = 10;
	cout << *a << endl;
	a++;
	*a = 20;
	cout << *a << endl;
	a++;
	*a = 30;
	cout << *a << endl;


	return EXIT_SUCCESS;
};
