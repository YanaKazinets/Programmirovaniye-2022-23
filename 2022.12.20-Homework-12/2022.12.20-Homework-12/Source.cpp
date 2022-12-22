#include <iostream>
#include <vector>
#include <ctime> 
#include <thread>

using namespace std;

void filling(vector<int> v)
{
	for (long int i = 0; i < v.size(); ++i)
	{
		v[i] = 1 + rand() % 100;
	}
}

void process(vector<int> a, vector<int> b, vector<int> c)
{
	for (long int i = 0; i < c.size(); ++i)
	{
		c[i] = a[i] + b[i];
	}
}

int main()
{
	srand(time(0));
	vector<int> a(1000000);
	vector<int> b(1000000);
	vector<int> c(1000000);

	filling(a);
	filling(b);
	
	process(a, b, c);
	
	cout << "Time: " << clock() << endl;
	
	return EXIT_SUCCESS;
}