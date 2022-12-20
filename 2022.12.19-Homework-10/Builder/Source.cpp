#include <iostream>
#include<string>
using namespace std;

class Jacket
{
public:
	string material;
	bool hood;
	int pockets;
	int buttons;
	bool zipper;
};

class Builder
{
public:
	virtual void CreateProduct() { }
	virtual void ChooseMat(string mat) { }
	virtual void AddHood(bool h) { }
	virtual void AddZipp(bool h) { }
	virtual void AddPock(int n) { }
	virtual void AddBut(int n) { }
	virtual Jacket* GetResult() { return nullptr; }
};

class CoatBuilder : public Builder
{
private:
	Jacket* adress;

public:
	CoatBuilder()
	{
		adress = nullptr;
	}

	virtual void CreateProduct()  override
	{
		adress = new Jacket();
	}

	virtual void ChooseMat(string mat)   override
	{
		adress->material = mat;
	}

	virtual void AddPock(int n)  override
	{
		adress->pockets = n;
	}

	virtual void AddBut(int n) override
	{
		adress->buttons = n;
	}

	virtual Jacket* GetResult()
	{
		return adress;
	}

	~CoatBuilder()
	{
		if (adress != nullptr)
			delete adress;
	}
};

class HoodyBuilder : public Builder
{
private:
	Jacket* adress;

public:
	HoodyBuilder()
	{
		adress = nullptr;
	}

	virtual void CreateProduct() override
	{
		adress = new Jacket();
	}

	virtual void ChooseMat(string mat) override
	{
		adress->material = mat;
	}

	virtual void AddHood(bool h) 
	{ 
		adress->hood = h;
	}

	virtual void AddPock(int n) override
	{
		adress->pockets = n;
	}

	virtual void AddZipp(bool e) override
	{
		adress->zipper = e;
	}

	virtual Jacket* GetResult()
	{
		return adress;
	}

	~HoodyBuilder()
	{
		if (adress != nullptr)
			delete adress;
	}
};


int main()
{
	Jacket* windbreaker;
	
	HoodyBuilder B;
	B.CreateProduct();
	B.ChooseMat("polyesther");
	B.AddHood(true);
	B.AddPock(3);
	B.AddZipp(false);

	windbreaker = B.GetResult();

	cout << windbreaker->material << endl;
	cout << windbreaker->buttons << endl;
	cout << windbreaker->pockets << endl;
	cout << windbreaker->hood << endl;
	cout << windbreaker->zipper << endl;

	delete windbreaker;

	return EXIT_SUCCESS;
}