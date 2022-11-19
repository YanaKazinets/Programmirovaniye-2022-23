#include<iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class player
{
protected:
	int chip5;
	int chip25;
	int chip100;

	int bet5;
	int bet25;
	int bet100;

	friend class Thief;
	friend class Bouncer;

public:
	player(int c5 = 20, int c25 = 8, int c100 = 5, int b5 = 0, int b25 = 0, int b100 = 0) : chip5(c5), chip25(c25), chip100(c100), bet5(b5), bet25(b25), bet100(b100) {}
	 
	void aside()
	{
		this->bet5 = 0;
		this->bet25 = 0;
		this->bet100 = 0;
	}
	void printChips()
	{
		cout << "5 chips: " << this->chip5 << endl;
		cout << "25 chips: " << this->chip25 << endl;
		cout << "100 chips: " << this->chip100 << endl;
	}
};


class Roulette : public player
{
private:
	int directBet;
	int dozenBet;
	int rawBet;
	string colorBet;

public:
	Roulette(int num = 0, int doz = 1, int raw = 1) : directBet(num), dozenBet(doz), rawBet(raw) {}

	void directBetting(int c5, int c25, int c100, int number)
	{
		if (this->chip5 >= c5 && this->chip25 >= c25 && this->chip100 >= c100 && number >= 0 && number <= 36)
		{
			this->chip5 -= c5;
			this->chip25 -= c25;
			this->chip100 -= c100;

			this->bet5 += c5;
			this->bet25 += c25;
			this->bet100 += c100;

			this->directBet = number;
		}
		else { cout << "Invalid bet" << endl; }
	}
	void directRes(int number)
	{
		if (this->directBet == number)
		{
			this->chip5 += 36 * this->bet5;
			this->chip25 += 36 * this->bet25;
			this->chip100 += 36 * this->bet100;
		}
		aside();
	}
	void dozenBetting(int c5, int c25, int c100, int number)
	{
		if (this->chip5 >= c5 && this->chip25 >= c25 && this->chip100 >= c100 && number >= 1 && number <= 3)
		{
			this->chip5 -= c5;
			this->chip25 -= c25;
			this->chip100 -= c100;

			this->bet5 += c5;
			this->bet25 += c25;
			this->bet100 += c100;

			this->dozenBet = number;
		}
		else { cout << "Invalid bet" << endl; }
	}
	void dosenRes(int number)
	{
		if (this->directBet == (number - 1)/12 + 1 && number != 0)
		{
			this->chip5 += 3 * this->bet5;
			this->chip25 += 3 * this->bet25;
			this->chip100 += 3 * this->bet100;
		}
		aside();
	}
	void rawBetting(int c5, int c25, int c100, int number)
	{
		if (this->chip5 >= c5 && this->chip25 >= c25 && this->chip100 >= c100 && number >= 1 && number <= 3)
		{
			this->chip5 -= c5;
			this->chip25 -= c25;
			this->chip100 -= c100;

			this->bet5 += c5;
			this->bet25 += c25;
			this->bet100 += c100;

			this->rawBet = number;
		}
		else { cout << "Invalid bet" << endl; }
	}
	void rawRes(int number)
	{
		if (this->rawBet % 3 == number % 3 && number != 0)
		{
			this->chip5 += 3 * this->bet5;
			this->chip25 += 3 * this->bet25;
			this->chip100 += 3 * this->bet100;
		}
		aside();
	}
	void colorBetting(int c5, int c25, int c100, string color)
	{
		if (this->chip5 >= c5 && this->chip25 >= c25 && this->chip100 >= c100 && (color == "red" || color == "black"))
		{
			this->chip5 -= c5;
			this->chip25 -= c25;
			this->chip100 -= c100;

			this->bet5 += c5;
			this->bet25 += c25;
			this->bet100 += c100;

			this->colorBet = color;
		}
		else { cout << "Invalid bet" << endl; }
	}
	void colorRes(string color)
	{
		if (this->colorBet == color)
		{
			this->chip5 += 2 * this->bet5;
			this->chip25 += 2 * this->bet25;
			this->chip100 += 2 * this->bet100;
		}
		aside();
	}
};


class Craps : public player
{
public:
	void Bet(int c5, int c25, int c100)
	{
		if (this->chip5 >= c5 && this->chip25 >= c25 && this->chip100 >= c100)
		{
			this->chip5 -= c5;
			this->chip25 -= c25;
			this->chip100 -= c100;

			this->bet5 += c5;
			this->bet25 += c25;
			this->bet100 += c100;
		}
		else { cout << "Invalid bet" << endl; }
	}
	void Res(int num)
	{
		if (num == 7 || num == 11)
		{
			this->chip5 += 2 * this->bet5;
			this->chip25 += 2 * this->bet25;
			this->chip100 += 2 * this->bet100;
		}
		else if(num != 2 && num != 3 && num != 12) 
		{
			this->chip5 += this->bet5;
			this->chip25 += this->bet25;
			this->chip100 += this->bet100;
		};
		aside();
	}
};

class Bouncer
{
public:
	void disqualify(player &Player)
	{
		Player.chip5 = 0;
		Player.chip25 = 0;
		Player.chip100 = 0;
	}
};
class Thief
{
public:
	void stealBet(player &Player)
	{
		Player.aside();
	}
};

int SpinTheRoulette()
{
	return rand() % 37;
};
string DropColor()
{
	int n = rand() % 37;
	if (n == 0) return "zero";
	else if (n % 2 == 0) return "black";
	else return "red";
};
int RollTheDice()
{
	return rand() % 11 + 2;
};

int main()
{
	srand(time(0));

	Craps Eren;
	Roulette Kilua;
	Roulette Mob;
	/*cout << "Eren: " << endl;
	Eren.printChips();
	cout << "Kilua: " << endl;
	Kilua.printChips();
	cout << "Mob: " << endl;
	Mob.printChips();*/

	Eren.Bet(0, 0, 5);
	int Sum = RollTheDice();
	Eren.Res(Sum);
	cout << "Sum is " << Sum << endl;
	cout << "Eren: " << endl;
	Eren.printChips();

	Kilua.directBetting(0, 4, 0, 25);
	int n = SpinTheRoulette();
	Kilua.directRes(n);
	cout << "Number is " << n << endl;
	cout << "Kilua: " << endl;
	Kilua.printChips();

	Bouncer Nanami;
	Nanami.disqualify(Kilua);
	cout << "Kilua: " << endl;
	Kilua.printChips();

	Mob.colorBetting(4, 3, 2, "red");

	Thief Toph;
	Toph.stealBet(Mob);
	cout << "Mob: " << endl;
	Mob.printChips();

	return EXIT_SUCCESS;
}