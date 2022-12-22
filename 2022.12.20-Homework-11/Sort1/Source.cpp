#include<fstream>
#include<iostream>
#include <algorithm>

using namespace std;

int main()
{
	ifstream InputFile("InputFile1.txt");

	int* numbers = new int[1000];

	for (int i = 0; i < 1000; ++i)
	{
		InputFile >> numbers[i];
	}
	sort(numbers, numbers + 1000);

	ofstream OutputFile("OutputOrig1.txt");

	int countik = 0;
	for (int i = 0; i < 1000; ++i)
	{
		OutputFile << numbers[i] << ' ';
	}

	delete[] numbers;
	InputFile.close();
	OutputFile.close();

	return EXIT_SUCCESS;
}