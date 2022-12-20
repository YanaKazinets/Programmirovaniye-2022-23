#include<iostream>
#include<string>

using namespace std;

class Sulu
{

protected:

	string function;  
	Sulu* successor;   

public:

	Sulu(string func, Sulu* adr = nullptr) : function(func), successor(adr) {}

	virtual ~Sulu()
	{
		delete successor;
	}

	Sulu* setsuccessor(Sulu* suc)
	{
		successor = suc;
		return successor;
	}

	virtual bool canDo(string request)
	{
		return (request == this->function);
	}

	virtual void doRequest(string request) = 0;

	virtual void handleRequest(string request)
	{
		if (this->canDo(request))
		{
			this->doRequest(request);
		}
		else
		{
			if (successor) {
				successor->handleRequest(request);
			}
			else {
				cout << "Request cannot be done." << endl;
			}
		}
	}
};

class MasterOne : public Sulu
{

protected:
	void doRequest(string request) override
	{
		cout << "MasterOne will do " << request << endl;
	}
public:
	MasterOne(string func, Sulu* adr) : Sulu(func, adr) {}
};

class MasterTwo : public Sulu
{

protected:
	void doRequest(string request) override
	{
		cout << "MasterTwo will do " << request << endl;
	}
public:
	MasterTwo(string func, Sulu* adr) : Sulu(func, adr) {}
};

class MasterThree : public Sulu
{

protected:
	void doRequest(string request) override
	{
		cout << "MasterThree will do " << request << endl;
	}
public:
	MasterThree(string func, Sulu* adr) : Sulu(func, adr) {}
};

int main()
{
	Sulu* Adele = new MasterOne("Nails", nullptr);
	Sulu* Gaziza = new MasterTwo("Hair", Adele);
	Sulu* Zhuma = new MasterThree("Feet", Gaziza);

	Zhuma->handleRequest("Nails");
	Gaziza->handleRequest("Makeup");

	return EXIT_SUCCESS;
}