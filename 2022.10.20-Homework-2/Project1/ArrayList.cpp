#include "ArrayList.h"

void ArrayList::expand(int count)
{
	int* newdata = new int[count + this->capacity];
	for (int i = 0; i < this->capacity; ++i)
	{
		newdata[i] = this->data[i];
	}
	delete[] this->data;
	this->data = newdata;
	this->capacity += count;
}

void ArrayList::swap(int posi, int posj)
{
	int el = this->data[posi];
	this->data[posi] = this->data[posj];
	this->data[posj] = el;
}

int ArrayList::ind(int index)
{
	if (index < 0)
	{
		pushbegin(0);
		return 0;
	}
	if (index >= this->count)
	{
		pushend(0);
		return this->count + 1;
	}
	return index;
}

ArrayList::ArrayList(int capacity)
{
	this->capacity = capacity;
	this->count = 0;
	this->data = new int[capacity];
}

ArrayList::ArrayList(const ArrayList& list)
{
	this->capacity = list.count;
	this->count = list.count;
	this->data = new int[list.count];
	for (int i = 0; i < list.count; ++i)
	{
		this->data[i] = list.data[i];
	}
}

ArrayList::~ArrayList()
{
	this->count = 0;
	this->capacity = 0;
	for (int i = 0; i < this->capacity; ++i)
	{
		this->data[i] = 0;
	}
	delete[] this->data;
}

int ArrayList::size()
{
	return this->count;
}

void ArrayList::pushend(int element)
{
	if (this->count == this->capacity)
	{
		expand(this->capacity);
	}
	this->data[this->count] = element;
	this->count++;
}

void ArrayList::pushbegin(int element)
{
	if (this->count == this->capacity)
	{
		expand(this->capacity);
	}
	for (int i = this->count; i > 0; --i)
	{
		this->data[i] = this->data[i - 1];
	}
	this->data[0] = element;
	this->count++;
}

void ArrayList::insert(int element, int position)
{
	if (this->count == this->capacity)
	{
		expand(this->capacity);
	}
	for (int i = this->count; i > position - 1; --i)
	{
		this->data[i] = this->data[i - 1];
	}
	this->data[position - 1] = element;
	this->count++;
}

int ArrayList::extractbegin()
{
	int el = this->data[0];
	for (int i = 0; i < this->count - 1; ++i)
	{
		this->data[i] = this->data[i + 1];
	}
	this->count--;
	return el;
}

int ArrayList::extractend()
{
	this->count--;
	return this->data[this->count];
}

int ArrayList::extract(int position)
{
	int el = this->data[position - 1];
	for (int i = position - 1; i < this->count - 1; ++i)
	{
		this->data[i] = this->data[i + 1];
	}
	this->count--;
	return el;
}

int& ArrayList::operator[](int pos)
{
	return data[ind(pos)];
}

void ArrayList::sort()
{
	for (int i = this->count -1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (this->data[j] > this->data[i])
			{
				swap(i, j);
			}
		}
	}
}

std::ostream& operator<<(std::ostream& stream, ArrayList& list)
{
	stream << "[" << list.count << "/" << list.capacity << "] {";
	if (list.count == 0)
	{
		stream << "EMPTY";
	}
	else
	{
		for (int i = 0; i < list.count - 1; ++i)
		{
			stream << list.data[i] << ", ";
		}
		stream << list.data[list.count - 1];
	}
	stream << "}";
	return stream;
}
