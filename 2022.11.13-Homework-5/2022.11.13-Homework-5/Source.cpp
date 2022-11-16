#include<iostream>

using namespace std;
template<typename t>

class Vector
{
public:
	t* data;
	int capacity;
	int count;

	Vector<t>(int capacity)
	{
		this->capacity = capacity;
		this->count = 0;
		data = new t[capacity];
	}
	
	Vector<t>(const Vector<t>& vector)
	{
		this->capacity = vector.count;
		this->count = vector.count;
		this->data = new t[vector.count];
		for (int i = 0; i < vector.count; ++i)
		{
			this->data[i] = vector.data[i];
		}
	}
	
	~Vector<t>()
	{
		this->count = 0;
		this->capacity = 0;
		delete[] this->data;
	}

	void expand(int count = 1)
	{
		t* newdata = new t[count + this->capacity];
		for (int i = 0; i < this->capacity; ++i)
		{
			newdata[i] = this->data[i];
		}
		delete[] this->data;
		this->data = newdata;
		this->capacity += count;
	}

	

	void pushend(t element)
	{
		if (this->count == this->capacity)
		{
			expand(this->capacity);
		}
		this->data[this->count] = element;
		this->count++;
	}

	void pushbegin(t element)
	{
		if (this->count == this->capacity)
		{
			expand(this->capacity);
		}
		pushend(0);
		for (int i = count - 1; i > 0; --i)
		{
			this->data[i] = this->data[i - 1];
		}
		this->data[0] = element;
	}

	void insert(t element, int pos)
	{
		if (pos <= 0)
		{
			pushbegin(element);
		}
		else if (pos >= (count - 1))
		{
			pushend(element);
		}
		else
		{
			pushend(0);
			for (int i = count - 1; i > pos; --i)
			{
				this->data[i] = this->data[i - 1];
			}
			this->data[pos] = element;
		}
	}

	t extractbegin()
	{
		int m = this->data[0];
		for (int i = 0; i < (count - 1); ++i)
		{
			this->data[i] = this->data[i + 1];
		}
		this->count--;
		return m;
	}

	t extractend()
	{
		this->count--;
		return this->data[this->count];
	}

	t extract(int pos)
	{
		if (pos <= 0)
		{
			return extractbegin();
		}
		else if (pos >= (count - 1))
		{
			return extractend();
		}
		else
		{
			int m = this->data[pos];
			for (int i = pos; i < (count - 1); ++i)
			{
				this->data[i] = this->data[i + 1];
			}
			this->count--;
			return m;
		}
	}
	
	int index(int index)
	{
		if (index < 0)
		{
			pushbegin(0);
			return 0;
		}
		if (index >= this->count)
		{
			pushend(0);
			return this->count - 1;
		}
		return index;
	}

	void swap(int i, int j)
	{
		int m = this->data[index(i)];
		this->data[index(i)] = this->data[index(j)];
		this->data[index(j)] = m;
	}


	t& operator[](int pos)
	{
		return data[index(pos)];
	}


	friend std::ostream& operator<<(std::ostream& stream, const Vector<t>& vector)
	{
		stream << "{";
		for (int i = 0; i < vector.count - 1; ++i)
		{
			stream << vector.data[i] << ", ";
		}
		stream << vector.data[vector.count - 1];
		stream << "}";
		return stream;
	}
	friend std::istream& operator>>(std::istream& stream, const Vector<t>& vector)
	{
		for (int i = 0; i < vector.capacity; ++i)
		{
			stream >> vector.data[i];
		}
		return stream;
	}

	Vector operator=(const Vector<t>& vector)
	{
		this->count = vector.count;
		this->capacity = vector.capacity;
		delete[] data;
		data = new int[capacity];
		for (int i = 0; i < this->count; ++i)
		{
			data[i] = vector.data[i];
		}
		return *this;
	}
};

int main(int argc, char* argv[])
{
	Vector<double> vector(1);

	vector[0] = 7;
	cout << vector << endl;
	
	vector.expand(3);
	
	vector[1] = -1;
	vector[2] = 3.7;
	vector[3] = 0;
	vector.pushend(-9.42);
	cout << vector << endl;

	cout << vector.extract(3) << endl;
	cout << vector << endl;

	return EXIT_SUCCESS;
}