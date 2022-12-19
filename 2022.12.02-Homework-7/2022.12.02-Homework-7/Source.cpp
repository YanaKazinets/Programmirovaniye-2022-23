#include<iostream>
#include<fstream>

using namespace std;

template<typename t>
class VectorM
{
public:
	t* data;
	int capacity;
	int count;
	
	VectorM<t>(int capacity)
	{
		this->capacity = capacity;
		this->count = 0;
		data = new t[capacity];
	}
	
	VectorM<t>(const VectorM<t>& vector)
	{
		this->capacity = vector.count;
		this->count = vector.count;
		this->data = new t[vector.count];
		for (int i = 0; i < vector.count; ++i)
		{
			this->data[i] = vector.data[i];
		}
	}
	
	~VectorM<t>()
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

	void insert(t element, int position)
	{
		if (position <= 0)
		{
			pushbegin(element);
		}
		else if (position >= (count - 1))
		{
			pushend(element);
		}
		else
		{
			pushend(0);
			for (int i = count - 1; i > position; --i)
			{
				this->data[i] = this->data[i - 1];
			}
			this->data[position] = element;
		}
	}
	
	

	

	
	t extractbegin()
	{
		t m = this->data[0];
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
			t m = this->data[pos];
			for (int i = pos; i < (count - 1); ++i)
			{
				this->data[i] = this->data[i + 1];
			}
			this->count--;
			return m;
		}
	}
	
	void swap(int i, int j)
	{
		t m = this->data[index(i)];
		this->data[index(i)] = this->data[index(j)];
		this->data[index(j)] = m;
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

	t& operator[](int pos)
	{
		return data[index(pos)];
	}


	friend std::ostream& operator<<(std::ostream& stream, const VectorM<t>& vector)
	{
		stream << "[" << vector.count << "/" << vector.capacity << "] {";
		if (vector.count == 0)
		{
			stream << "EMPTY";
		}
		else
		{
			for (int i = 0; i < vector.count - 1; ++i)
			{
				stream << vector.data[i] << ", ";
			}
			stream << vector.data[vector.count - 1];
		}
		stream << "}";
		return stream;
	}
	
	friend std::istream& operator>>(std::istream& stream, const VectorM<t>& vector)
	{
		for (int i = 0; i < vector.capacity; ++i)
		{
			stream >> vector.data[i];
		}
		return stream;
	}

	VectorM operator=(const VectorM<t>& vector)
	{
		if (&vector == this)
		{
			return *this;
		}
		this->count = vector.count;
		this->capacity = vector.capacity;
		delete[] data;
		data = new t[capacity];
		for (int i = 0; i < this->count; ++i)
		{
			data[i] = vector.data[i];
		}
		return *this;
	}

};

template<class T>
void write_in_file(VectorM<T> &vector, string adr)
{
	ofstream file(adr);
	int n = (vector.count) * (sizeof vector.data[0]);
	file << vector.count;
	file.write(reinterpret_cast<char*>(vector.data), n);
	file.close();
}

template<class T>
VectorM<T> read_from_file(ifstream& file)
{
	file.clear();
	file.seekg(0);
	int b = 0;
	file >> b;
	VectorM<T> v(b);
	char* ch = new char[b * sizeof(T) + 1];
	ch[b * sizeof(T)] = 0;
	file.read(ch, b * sizeof(T));
	v.count = b;
	v.data = reinterpret_cast<T*>(ch);
	return v;
	file.close();
}

int main(int argc, char** argv)
{
	
	VectorM<char> vectorChar(5);
	vectorChar[0] = 'b';
	vectorChar[1] = '#';
	vectorChar[2] = '-';
	vectorChar[3] = '/';
	vectorChar[4] = '[';

	write_in_file(vectorChar, "OutputFile.txt");
	
	ifstream inFile("OutputFile.txt");
	
	cout << read_from_file<char>(inFile);
	
	return EXIT_SUCCESS;
}