#include <iostream>
using namespace std;

class Sponge
{
public:
	virtual void Bake() = 0;
};
class Classic :public Sponge
{
public:

	void Bake() override
	{
		cout << "Bake classic sponge" << endl;
	}
};
class Chocolate :public Sponge
{
public:

	void Bake() override
	{
		cout << "Bake chokolate sponge" << endl;
	}
};
class Citrus :public Sponge
{
public:

	void Bake() override
	{
		cout << "Bake sponge with zest" << endl;
	}
};

class Cream
{
public:
	virtual void Mix() = 0;
};

class Chease : public Cream
{
public:

	void Mix() override
	{
		cout << "Mix cream-chease" << endl;
	}
};
class Ganache :public Cream
{
public:

	void Mix() override
	{
		cout << "Mix chokolate ganache" << endl;
	}
};

class Filling
{
public:
	virtual void Cook() = 0;
};
class Berry :public Filling
{
public:

	void Cook() override
	{
		cout << "Cook berry filling" << endl;
	}
};
class Crisp :public Filling
{
public:

	void Cook() override
	{
		cout << "Cook crispy layer" << endl;
	}
};
class Caramel :public Filling
{
public:

	void Cook() override
	{
		cout << "Cook caramel" << endl;
	}
};


class Confectioner
{
public:
	Sponge* sponge;
	Cream* cream;
	Filling* fill;
	
	Confectioner(Sponge* s, Cream* c, Filling* f) : sponge(s), cream(c), fill(f) {}
	virtual ~Confectioner() {}
	
	virtual void MakeDessert() = 0;
};

class CakeMaker : public Confectioner
{
public:
	
	CakeMaker(Sponge* s, Cream* c, Filling* f) : Confectioner(s, c, f) {}
	
	virtual void MakeDessert() override
	{
		cout << "Making cake:" << endl;
		this->sponge->Bake();
		this->cream->Mix();
		this->fill->Cook();
	}
};

class TrifleMaker : public Confectioner
{
public:

	TrifleMaker(Sponge* s, Cream* c, Filling* f) : Confectioner(s, c, f) {}

	virtual void MakeDessert() override
	{
		cout << "Making trifle:" << endl;
		this->sponge->Bake();
		this->cream->Mix();
		this->fill->Cook();
	}
};

int main()
{
	Sponge* sponge = new Classic;
	Cream* cream = new Ganache;
	Filling* fill = new Caramel;
	
	CakeMaker Cooker(sponge, cream, fill);

	Cooker.MakeDessert();

	return EXIT_SUCCESS;
}