#include "Fraction.h"

long long mod(long long n)
{
	if (n >= 0) { return n; }
	else return (-n);
}
int sign(long long n)
{
	if (n >= 0) { return 1; }
	else { return -1; }
}

long long nod(long long n, long long m)
{
	n = mod(n);
	m = mod(m);
	while (n - m != 0)
	{
		if (n > m) { n -= m; }
		else { m -= n; }
	}
	return n;
}
long long nok(long long n, long long m)
{
	return ((n*m) / nod(n, m));
}

Fraction::Fraction(long long numerator, long long denominator)
{
	this->numerator = numerator * sign(denominator) / nod(numerator, denominator);
	this->denominator = mod(denominator) / nod(numerator, denominator);
}

Fraction::Fraction(const Fraction & fraction)
{
	this->numerator = fraction.numerator;
	this->denominator = fraction.denominator;
}

Fraction::~Fraction()
{
	this->numerator = 0;
	this->denominator = 0;
}

void Fraction::setNumerator(long long numerator)
{ 
	this->numerator = numerator;
}

void Fraction::setDenominator(long long denominator)
{
	this->denominator = denominator;
}

long long Fraction::getNumerator()
{
	return this->numerator;
}

long long Fraction::getDenominator()
{
	return this->denominator;
}

Fraction & Fraction::operator=(const Fraction & fraction)
{
	this->numerator = fraction.numerator;
	this->denominator = fraction.denominator;
	return *this;
}

Fraction Fraction::reverse()
{
	return Fraction(-this->numerator, this->denominator);
}

Fraction Fraction::abs()
{
	return Fraction(mod(this->numerator), mod(this->denominator));
}

std::ostream & operator<<(std::ostream & stream, const Fraction & fraction)
{
	stream << fraction.numerator << "/" << fraction.denominator;
	return stream;
}

bool operator==(const Fraction & frac1, const Fraction& frac2)
{
	if ((frac1.numerator * frac2.denominator) == (frac2.numerator * frac1.denominator))
	{
		return true;
	}
	else { return false; }
}

bool operator>=(const Fraction & frac1, const Fraction & frac2)
{
	if ((frac1.numerator * frac2.denominator) >= (frac2.numerator * frac1.denominator))
	{
		return true;
	}
	else { return false; }
}

bool operator<=(const Fraction & frac1, const Fraction & frac2)
{
	if ((frac1.numerator * frac2.denominator) <= (frac2.numerator * frac1.denominator))
	{
		return true;
	}
	else { return false; }
}

bool operator>(const Fraction & frac1, const Fraction & frac2)
{
	if ((frac1.numerator * frac2.denominator) > (frac2.numerator * frac1.denominator))
	{
		return true;
	}
	else { return false; }
}

bool operator<(const Fraction & frac1, const Fraction & frac2)
{
	if ((frac1.numerator * frac2.denominator) < (frac2.numerator * frac1.denominator))
	{
		return true;
	}
	else { return false; }
}

Fraction operator+(const Fraction & frac1, const Fraction & frac2)
{
	return Fraction((frac1.numerator * frac2.denominator) + (frac2.numerator * frac1.denominator), frac1.denominator * frac2.denominator);
}
Fraction operator-(const Fraction & frac1, const Fraction & frac2)
{
	return Fraction((frac1.numerator * frac2.denominator) - (frac2.numerator * frac1.denominator), frac1.denominator * frac2.denominator);
}
Fraction operator*(const Fraction & frac1, const Fraction & frac2)
{
	return Fraction(frac1.numerator * frac2.numerator, frac1.denominator * frac2.denominator);
}
Fraction operator*(long long mult, const Fraction & frac)
{
	return Fraction((mult * frac.numerator), frac.denominator);
}
Fraction operator*(const Fraction & frac, long long mult)
{
	return Fraction((mult * frac.numerator), frac.denominator);
}
Fraction operator/(const Fraction & frac1, const Fraction & frac2)
{
	return Fraction(frac1.numerator * frac2.denominator, frac1.denominator * frac2.numerator);
}
Fraction operator/(long long mult, const Fraction & frac)
{
	return Fraction(mult * frac.denominator, frac.numerator);
}
Fraction operator/(const Fraction & frac, long long mult)
{
	return Fraction(frac.denominator, mult * frac.numerator);
}
// a/b : c/d = a/b * d/c

