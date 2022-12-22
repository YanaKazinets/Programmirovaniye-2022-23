#include <iostream>
#include <vector>
#include <ctime> 
#include <thread>

using namespace std;

void filling(vector<int> v)
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		v[i] = 1 + rand() % 100;
	}
}

void process(vector<int> a, vector<int> b, vector<int> c)
{
	for (size_t i = 0; i < c.size(); ++i)
	{
		c[i] = a[i] + b[i];
	}
}

int main()
{
	srand(time(0));
	vector<int> a1(500000);
	vector<int> a2(500000);
	vector<int> b1(500000);
	vector<int> b2(500000);
	vector<int> c1(500000);
	vector<int> c2(500000);

	thread sa1(filling, a1);
	thread sb1(filling, a2);
	thread sa2(filling, a1);
	thread sb2(filling, a2);

	//filling, b1, process, a1, b1, c1
	sa1.join();
	sb1.join();
	sa2.join();
	sb2.join();

	thread sc1(process, a1, b1, c1);
	thread sc2(process, a2, b2, c2);

	sc1.join();
	sc2.join();

	cout << "Time: " << clock() << endl;

	return EXIT_SUCCESS;
}