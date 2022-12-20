#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Archer
{
public:
	void fire()
	{
		cout << "shoot" << endl;
	}
	void hide()
	{
		cout << "out of sight" << endl;
	}
	void depart()
	{
		cout << "left" << endl;
	}
};

class Command
{
protected:
	Archer* archer;
	Command(Archer* a) : archer(a) {}
	
public:
	virtual ~Command() {}
	virtual void perform() = 0;
};

class Fire : public Command
{
public:
	Fire(Archer * a) : Command(a) {}
	
	void perform() 
	{
		archer->fire();
	}
};

class Hide : public Command
{
public:
	Hide(Archer* a) : Command(a) {}
	void perform() 
	{
		archer->hide();
	}
};

class Depart : public Command
{
public:
	Depart(Archer * p) : Command(p) {}
	void perform()
	{
		archer->depart();
	}
};

class Signalman
{
public:
	void send(Command* com)
	{
		com->perform();
	}
};

int main()
{
	Archer* Alia = new Archer();

	Fire* f1 = new Fire(Alia);
	Depart* D = new Depart(Alia);
	
	Signalman Azat;

	Azat.send(f1);
	Azat.send(D);

	return EXIT_SUCCESS;
}