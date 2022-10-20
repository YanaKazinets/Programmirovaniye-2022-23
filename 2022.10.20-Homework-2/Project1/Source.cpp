#include<iostream>
#include"ArrayList.h"

using namespace std;

int main(int argc, char* argv[])
{
	ArrayList arr;

	arr.pushend(9);
	arr.pushend(5);
	arr.pushend(8);
	arr.pushend(4);
	arr.pushend(11);
	arr.pushend(13);
	arr.pushend(7);
	arr.pushend(2);
	arr.pushend(0);
	arr.pushbegin(10);
	

	cout << arr << endl;
	cout<< arr.extractbegin() << endl;
	cout << arr << endl;
	cout << arr.extract(2) << endl;
	cout << arr << endl;
	arr.insert(6, 7);
	cout << arr << endl;

	arr.sort();
	cout << arr << endl;
	cout << arr.extractend();


	return EXIT_SUCCESS;
}