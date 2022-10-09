#pragma once
#include <iostream>

class Quaternion
{
private:
	double l;
	double i;
	double j;
	double k;

public:
	Quaternion(double l = 0, double i = 0, double j = 0, double k = 0);
	Quaternion(const Quaternion& quaternion);
	~Quaternion();

	void print();

	Quaternion& operator=(const Quaternion& quaternion);
	friend Quaternion operator+(const Quaternion& quatr1, const Quaternion& quatr2);
	friend Quaternion operator-(const Quaternion& quatr1, const Quaternion& quatr2);
	friend Quaternion operator*(const Quaternion& quatr1, const Quaternion& quatr2);
	friend Quaternion operator*(double mult, const Quaternion& quaternion);
	friend Quaternion operator*(const Quaternion& quaternion, double mult);
	friend Quaternion operator/(const Quaternion& quaternion, double mult);

	Quaternion reverse();
	Quaternion conj();
	double abs();
};

