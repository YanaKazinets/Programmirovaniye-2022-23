#include<iostream>
#include<string>

using namespace std;

class Instrument
{
public:
	string musician;
	int group;
	int position;
	
	Instrument(string name = "Musician name", int gr = 0, int pos = 0) : musician(name), group(gr), position(pos) {}
	
	void setName(string name)
	{
		this->musician = name;
	}
	void setGroup(int gr)
	{
		this->group = gr;
	}
	void setPos(int pos)
	{
		this->position = pos;
	}

	void printName()
	{
		cout << "Musitian name: " << this->musician << endl;
	}
	virtual void printPosition()
	{
		cout << "Group: " << this->group << " Position: " << this->position << endl;
	}
};

class Bowed : public Instrument
{
public:
	string tuning;
	double BodyLength;
	double BowLength;
	
	Bowed(string tun = "Gm  D1 A1 E2", double bdl = 60, double bwl = 74) : tuning(tun), BodyLength(bdl), BowLength(bwl) {}
	
	void printTuning()
	{
		cout << "Tuning: " << this->tuning << endl;
	}
	void printDimentions()
	{
		cout << "Body length: " << this->BodyLength << endl << "Bow length: " << this->BodyLength << endl;;
	}
};

class Violine : public Bowed
{
public:
	int priority;
	
	Violine(int pr = 1) : priority(pr) {}

	void printPosition()
	{
		cout << "Group: " << this->group << " Position: " << this->position << " (priority " << this->priority << ")" << endl;
	}
};

class Wind : public Instrument
{
public:
	string material;
	string VibSource;

	Wind(string mat = "copper", string vs = "labial") : material(mat), VibSource(vs) {}

	void printParameters()
	{
		cout << "Material: " << this->material << endl << "Vibration source: " << this->VibSource << endl;;
	}
};


int main(int argc, char* argv[])
{
	Violine FirstVioline;
	FirstVioline.setName("Condratiev");

	cout << "First violine:" << endl;
	FirstVioline.printName();
	FirstVioline.printTuning();
	FirstVioline.printPosition();

	cout << "Xylophone:" << endl;
	Instrument Xylophone("Jakkins", 14);

	Xylophone.printPosition();

	return EXIT_SUCCESS;
}