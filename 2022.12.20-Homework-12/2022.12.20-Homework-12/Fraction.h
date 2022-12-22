#pragma once
#include<iostream>

class Fraction
{
private:
	long long numerator;
	long long denominator;

public:
	Fraction(long long numenator = 0, long long denominator = 1);
	Fraction(const Fraction& fraction);
	~Fraction();

	void setNumerator(long long numerator);
	void setDenominator(long long denominator);
	long long getNumerator();
	long long getDenominator();
	Fraction& operator=(const Fraction& fraction);

	friend std::ostream& operator<<(std::ostream& stream, const Fraction& fraction);

	friend bool operator==(const Fraction& frac1, const Fraction& frac2);
	friend bool operator>=(const Fraction& frac1, const Fraction& frac2);
	friend bool operator<=(const Fraction& frac1, const Fraction& frac2);
	friend bool operator>(const Fraction& frac1, const Fraction& frac2);
	friend bool operator<(const Fraction& frac1, const Fraction& frac2);

	friend Fraction operator+(const Fraction& frac1, const Fraction& frac2);
	friend Fraction operator-(const Fraction& frac1, const Fraction& frac2);
	friend Fraction operator*(const Fraction& frac1, const Fraction& frac2);
	friend Fraction operator*(long long mult, const Fraction& frac);
	friend Fraction operator*(const Fraction& frac, long long mult);
	friend Fraction operator/(const Fraction& frac1, const Fraction& frac2);
	friend Fraction operator/(long long mult, const Fraction& frac);
	friend Fraction operator/(const Fraction& frac, long long mult);

	Fraction reverse();
	Fraction abs();



};

