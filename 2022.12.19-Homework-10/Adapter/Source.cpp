#include <iostream>
using namespace std;


class Egg
{
public:
	bool integrity = true;
	virtual void Breaking()
	{
		this->integrity = false;
		cout << "toc" << endl;
	}
};

class EnemySkull
{
public:
	bool integrity = true;
	void SkullBreaking()
	{
		this->integrity = false;
		cout << "Crack!" << endl;
	}
};

class Adapter :public Egg
{
private:
	EnemySkull* SkullAdr;

public:
	
	Adapter(EnemySkull* link) : SkullAdr(link) {}

	void Breaking() override
	{
		SkullAdr->SkullBreaking();
	}
};

class Cooker
{
public:
	void Break(Egg* egg)
	{
		egg->Breaking();
	}
};

int main()
{
	Cooker Helga;

	EnemySkull Piras;
	Egg* NotEgg;

	NotEgg = new Adapter(&Piras);

	cout << Piras.integrity << endl;
	Helga.Break(NotEgg);
	cout << Piras.integrity << endl;

	delete NotEgg;

	return EXIT_SUCCESS;
}