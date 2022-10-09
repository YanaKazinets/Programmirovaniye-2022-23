#include "Quaternion.h"

Quaternion::Quaternion(double l, double i, double j, double k) : l(l), i(i), j(j), k(k) {}

Quaternion::Quaternion(const Quaternion & quaternion) : l(quaternion.l), i(quaternion.i), j(quaternion.j), k(quaternion.k) {}

Quaternion::~Quaternion()
{
	this->l = 0;
	this->i = 0;
	this->j = 0;
	this->k = 0;
}

void Quaternion::print()
{
	if (this->l != 0) { std::cout << this->l; }
	if (this->i > 0) { std::cout << "+"; }
	if (this->i != 0) { std::cout << this->i << "i"; }
	if (this->j > 0) { std::cout << "+"; }
	if (this->j != 0) { std::cout << this->j << "j"; }
	if (this->k > 0) { std::cout << "+"; }
	if (this->k != 0) { std::cout << this->k << "k"; }
	std::cout << std::endl;
}

Quaternion & Quaternion::operator=(const Quaternion & quaternion)
{
	this->l = quaternion.l;
	this->i = quaternion.i;
	this->j = quaternion.j;
	this->k = quaternion.k;
	return *this;
}

Quaternion Quaternion::reverse()
{
	return Quaternion(-this->l, -this->i, -this->j, -this->k);
}

Quaternion Quaternion::conj()
{
	return Quaternion(this->l, -this->i, -this->j, -this->k);
}

double Quaternion::abs()
{
	return (double) this->l*this->l + this->i * this->i + this->j * this->j + this->k * this->k ;
}

Quaternion operator+(const Quaternion & quatr1, const Quaternion & quatr2)
{
	return Quaternion(quatr1.l + quatr2.l, quatr1.i + quatr2.i, quatr1.j + quatr2.j, quatr1.k + quatr2.k);
}

Quaternion operator-(const Quaternion & quatr1, const Quaternion & quatr2)
{
	return Quaternion(quatr1.l - quatr2.l, quatr1.i - quatr2.i, quatr1.j - quatr2.j, quatr1.k - quatr2.k);
}

Quaternion operator*(const Quaternion & quatr1, const Quaternion & quatr2)
{
	return Quaternion(quatr1.l*quatr2.l - (quatr1.i*quatr2.i + quatr1.j*quatr2.j + quatr1.k*quatr2.k), quatr1.l*quatr2.i + quatr2.l*quatr1.i + quatr1.j*quatr2.k - quatr1.k*quatr2.j, quatr1.l*quatr2.j + quatr2.l*quatr1.j + quatr1.i*quatr2.k - quatr1.k*quatr2.i, quatr1.l*quatr2.k + quatr2.l*quatr1.k + quatr1.i*quatr2.j - quatr1.j*quatr2.i);
}

Quaternion operator*(double mult, const Quaternion & quaternion)
{
	return Quaternion(mult * quaternion.l, mult * quaternion.i, mult * quaternion.j, mult * quaternion.k);
}

Quaternion operator*(const Quaternion & quaternion, double mult)
{
	return Quaternion(mult * quaternion.l, mult * quaternion.i, mult * quaternion.j, mult * quaternion.k);
}

Quaternion operator/(const Quaternion & quaternion, double mult)
{
	return Quaternion( quaternion.l / mult, quaternion.i / mult, quaternion.j / mult, quaternion.k / mult);
}
