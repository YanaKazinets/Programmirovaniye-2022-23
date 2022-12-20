#include<iostream>
#include<string>

using namespace std;

class Storage
{
protected:
	int xpos;
	int ypos;
	int xp;
	int energy;
	int missions;
	friend class Player;
public:
	Storage(int X, int Y, int XP, int E, int M) : xpos(X), ypos(Y), xp(XP), energy(E), missions(M) {}
};

class Player
{
private:
	int xpos;
	int ypos;
	int xp;
	int energy;
	int missions;
public:
	Player(int X, int Y, int XP, int E, int M) : xpos(X), ypos(Y), xp(XP), energy(E), missions(M) {}
	void print()
	{
		cout << this->xpos << endl;
		cout << this->ypos << endl;
		cout << this->xp << endl;
		cout << this->energy << endl;
		cout << this->missions << endl;
	}
	void getHeated()
	{
		this->xp -= 2;
	}
	void completeMission()
	{
		this->missions += 1;
	}
	void goAhead()
	{
		this->ypos += 1;
		this->energy -= 1;
	}
	void goRight()
	{
		this->xpos += 1;
		this->energy -= 1;
	}
	void goLeft()
	{
		this->xpos -= 1;
		this->energy -= 1;
	}

	Storage* save()
	{
		return new Storage(this->xpos, this->ypos, this->xp, this->energy, this->missions);
	}
	void restore(Storage* copy)
	{
		this->xpos = copy->xpos;
		this->ypos = copy->ypos;
		this->xp = copy->xp;
		this->energy = copy->energy;
		this->missions = copy->missions;
	}
};

int main()
{
	Player Echa(0, 0, 100, 1000, 0);

	Storage* copy1 = Echa.save();
	Echa.goAhead();
	Echa.goAhead(); 
	Echa.goAhead();
	Echa.getHeated();
	Echa.goLeft();
	Echa.completeMission();
	Echa.print();
	Echa.restore(copy1);
	Echa.print();


	return EXIT_SUCCESS;
}