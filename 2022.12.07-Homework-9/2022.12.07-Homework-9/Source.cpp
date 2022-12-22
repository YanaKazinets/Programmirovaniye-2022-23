#include<iostream>
#include<fstream>
#include<map>
#include<string>

using namespace std;

class Dictionary
{
	map<string, string> trans;

public:
	
	void print()
	{
		map<string, string>::iterator it = trans.begin();
		while (it != trans.end())
		{
			cout << it->first << " " << it->second << endl;
			++it;
		}
	}
	
	void AddWord(string orig, string conv)
	{
		trans[orig] = conv;
	}
	
	void GetDict(string Adr)
	{
		ifstream file(Adr);
		while (!file.eof())
		{
			string orig, conv;
			getline(file, orig, ' ');
			getline(file, conv);
			trans[orig] = conv;
		}
		file.close();
	}
	
	void OFLsearch(char l)
	{
		map<string, string>::iterator it = trans.begin();
		while (it != trans.end())
		{
			if (it->first[0] == l)
			{
				cout << it->first << " " << it->second << endl;
			}
			++it;
		}
	}
	
	void TFLsearch(char l)
	{
		map<string, string>::iterator it = trans.begin();
		while (it != trans.end())
		{
			if (it->second[0] == l)
				cout << it->first << " " << it->second << endl;
			++it;
		}
	}
	
	void OrigWordSearch(string word)
	{
		map<string, string>::iterator it = trans.begin();
		while (it != trans.end())
		{
			if (it->first == word)
			{
				cout << it->first << " " << it->second << endl;
				return;
			}
			++it;
		}
	}
	
	void TransWordSearch(string word)
	{
		map<string, string>::iterator it = trans.begin();
		while (it != trans.end())
		{
			if (it->second == word)
				cout << it->first << " " << it->second << endl;
			++it;
		}
	}
	
	void DirectTrans(string InAdr, string OutAdr)
	{
		ifstream InputFile(InAdr);
		ofstream OutputFile(OutAdr);
		while (!InputFile.eof())
		{
			string word;
			getline(InputFile, word, ' ');
			OutputFile << trans[word] << " ";
		}
		InputFile.close();
		OutputFile.close();
	}
	
	void ReverseTrans(string InAdr, string OutAdr)
	{
		ifstream InputFile(InAdr);
		ofstream OutputFile(OutAdr);
		map<string, string>::iterator it = trans.begin();
		while (!InputFile.eof())
		{
			string word;
			getline(InputFile, word, ' ');
			while ((it != trans.end()) && (it->second != word))
			{
				++it;
			}
			OutputFile << it->first << " ";
			it = trans.begin();
		}
		InputFile.close();
		OutputFile.close();
	}
};

int main()
{
	Dictionary esp_rus;
	esp_rus.GetDict("Dictionary.txt");
	esp_rus.print();
	esp_rus.OFLsearch('q');
	esp_rus.DirectTrans("origin.txt", "translation.txt");
	
	return EXIT_SUCCESS;
}