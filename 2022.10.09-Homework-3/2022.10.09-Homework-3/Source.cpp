#include<iostream>
#include"Quaternion.h"

using namespace std;

int main()
{
	Quaternion q(1, 1, 2, 1);
	cout << q.abs();

	return EXIT_SUCCESS;
}