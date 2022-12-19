#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	ifstream InputFile;
	string InAdr;
	ofstream OutputFile;
	string OutAdr;
	
	cout << "Input file adress: ";
	cin >> InAdr;
	cout << endl;
	
	int n = 0;
	InputFile.open(InAdr); // Validness
	InputFile >> n; // Type 
	

	double a = 0;
	double b = 0;
	char oper;
	double *arr = new double[n];

	for (int i = 0; i < n; ++i)
	{
		InputFile >> a >> oper >> b;  // Types, existing
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
		case '/': // b = 0
			arr[i] = a / b;
			break;
		}
	}
	InputFile.close();
	cout << "Output file adress: ";
	cin >> OutAdr;
	OutputFile.open(OutAdr); // Valid / taken
	cout << "Number of strings:";
	int n1;
	cin >> n1; // Validness
	for (int i = 0; i < n1; ++i)
	{
		OutputFile << arr[i] << endl; // Existing
	}
	OutputFile.close();
	
	return EXIT_SUCCESS;
}