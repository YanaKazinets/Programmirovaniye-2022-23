#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	try {
		ifstream InputFile;
		string InAdr;
		ofstream OutputFile;
		string OutAdr;

		cout << "Input file adress: ";
		cin >> InAdr;
		cout << endl;

		int n = 0;
		InputFile.open(InAdr);
		if (!InputFile.is_open()) { throw ("File not found"); }
				
		string ns;
		InputFile >> ns;
		for (int i = 0; i < ns.size(); ++i)
		{
			if (ns[i] >= 48 && ns[i] <= 57) { n += (ns[i] - '0')*pow(10, ns.size() - i - 1); }
			else throw ("Wrong file format");
		}

		double a = 0;
		double b = 0;
		char oper;
		double* arr = new double[n];
		string s;
		for (int i = 0; i < n; ++i)
		{
			if (InputFile.eof()) throw ("Empty");
			
			InputFile >> s;
			int j = 0;
			string chr = "";
			while (s[j] >= 48 && s[j] <= 57)
			{
				chr += s[j];
				++j;
			}
			if (chr != "") { a = stoi(chr); }
			else throw ("No number");
			
			oper = s[j];
			if (oper != '+' && oper != '-' && oper != '*' && oper != '/')
			{
				throw ("Wrong symbol");
			}
			
			++j;
			chr = "";
			while (s[j] >= 48 && s[j] <= 57)
			{
				chr += s[j];
				++j;
			}
			if (chr != "") b = stoi(chr);
			else throw ("No number");

			switch (oper)
			{
			case  '+':
				arr[i] = a + b;
				break;
			case '-':
				arr[i] = a - b;
				break;
			case '*':
				arr[i] = a * b;
				break;
			case '/':
				if (b == 0) { throw ("Division by zero"); }
				arr[i] = a / b;
				break;
			default:
				throw "Error";
				break;
			}
		}
		InputFile.close();
		
		cout << "Output file adress:";
		cin >> OutAdr;
		if (InAdr == OutAdr) { throw ("Record address is the same as file address"); }
		OutputFile.open(OutAdr);
		cout << "Number of strings:";
		int n1 = 0;
		string ns1;
		cin >> ns1; 
		for (int i = 0; i < ns1.size(); ++i)
		{
			if (ns1[i] >= 48 && ns1[i] <= 57) { n1 += (ns1[i] - '0')*pow(10, ns1.size() - i - 1); }
			else throw ("Wrong file format");
		}

		if (n1 > n) throw ("No more strings");
		for (int i = 0; i < n1; ++i)
		{
			OutputFile << arr[i] << endl;
		}
		OutputFile.close();
	}
	catch (const char* error)
	{
		cout << error;
	}
	return EXIT_SUCCESS;
}