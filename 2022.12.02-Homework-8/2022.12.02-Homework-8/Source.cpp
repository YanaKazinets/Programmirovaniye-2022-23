#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void print()
{
	cout << "1" << endl;
}

void ttt(int a)
{
	cout << a << endl;
}

int adder(int a)
{
	return a + 1;
}

int adder2(int a, int b)
{
	return a + b;
}

using adr = void(*)();
using adr1 = void(*)(int a);
using adr1i = int(*)(int a);
using adr2 = int(*)(int a, int b);


class NoargLog
{
	int countik;
	adr adress;
	ofstream OutputFile;

public:	
	NoargLog(adr a) 
	{
		this->countik = 0;
		this->adress = a;
		OutputFile.open("Log.txt");
	}

	~NoargLog()
	{
		OutputFile.close();
	}
	
	void operator()()
	{
		++this->countik;
		this->adress();
		OutputFile <<"Entering " << this->countik << endl; 
		/*OutputFile << arg << endl;
		OutputFile << void(arg) << endl;*/
	}
};

class UnarLog
{
	int countik;
	adr1 adress;
	ofstream OutputFile;
public:
	UnarLog(adr1 a)
	{
		this->countik = 0;
		this->adress = a;
		OutputFile.open("Log1.txt");
	}

	~UnarLog()
	{
		OutputFile.close();
	}

	void operator()(int arg)
	{
		++this->countik;
		this->adress(arg);
		OutputFile << "Entering " << this->countik << endl;
		OutputFile << "Argument: " << arg << endl;
	}
};
class UnarLogi
{
	int countik;
	adr1i adress;
	ofstream OutputFile;
public:
	UnarLogi(adr1i a)
	{
		this->countik = 0;
		this->adress = a;
		OutputFile.open("Log1i.txt");
	}

	~UnarLogi()
	{
		OutputFile.close();
	}

	int operator()(int arg)
	{
		++this->countik;
		OutputFile << "Entering " << this->countik << endl;
		OutputFile << "Argument: " << arg << endl;
		OutputFile << "Value: " << this->adress(arg);
		return this->adress(arg);
	}
};

class BinarLog
{
	int countik;
	adr2 adress;
	ofstream OutputFile;
public:
	BinarLog(adr2 a)
	{
		this->countik = 0;
		this->adress = a;
		OutputFile.open("Log2.txt");
	}

	~BinarLog()
	{
		OutputFile.close();
	}

	int operator()(int arg1, int arg2)
	{
		++this->countik;
		OutputFile << "Entering " << this->countik << endl;
		OutputFile << "Arguments: " << arg1 << ", " << arg2 << endl;
		OutputFile << "Value: " << this->adress(arg1, arg2);
		return this->adress(arg1, arg2);
	}
};


	int main()
	{
		adr func0 = &print;
		adr1 func1 = &ttt;
		adr1i func1i = &adder;
		adr2 func2 = &adder2;

		NoargLog log(func0);
		UnarLog log1(func1);
		UnarLogi log1i(func1i);
		BinarLog log2(func2);

		log();
		log();
		log();
		log1(3);
		log1(32);
		cout << log1i(7) << endl;
		cout << log2(6, 10) << endl;

		return EXIT_SUCCESS;
	}