#include <iostream>
#include <list>
using namespace std;

class Hash
{
	int size;
	list<int>* table;

public:
	Hash(int a);
	int hashFunction(int num);
	void insert(int num);
	void deleteValue(int num);
	bool search(int num);
	void displayValues();
};

Hash::Hash(int a)
{
	size = a;
	table = new list<int>[a];
};

int Hash::hashFunction(int num)
{
	int index = num % size;

	return index;
}

void Hash::insert(int num)
{
	int index = hashFunction(num);

	table[index].push_back(num);
}

bool Hash::search(int num)
{
	int index = hashFunction(num);

	list<int>::iterator it;

	it = table[index].begin();

	for (it; it != table[index].end(); it++)
	{
		if (*it == num) break;
	}

	if (it != table[index].end()) return true;
}

void Hash::deleteValue(int num)
{
	int index = hashFunction(num);
	
	list<int>::iterator it;

	it = table[index].begin();

	for (it; it != table[index].end(); it++)
	{
		if (*it == num) break;
	}

	if (it != table[index].end()) table[index].erase(it);
}

void Hash::displayValues()
{
	for (int i = 0; i < size; i++)
	{
		list<int>::iterator it;
		it = table[i].begin();

		for (it; it != table[i].end(); it++)
		{
			cout << *it << endl;
		}
	}
}

int main()
{
	Hash H(5);

	H.insert(11);
	H.insert(12);
	H.insert(13);
	H.insert(9);
	H.insert(10);
	H.insert(20);
	H.insert(30);

	H.displayValues();

	return 0;
}
