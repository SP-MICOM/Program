#include <iostream>

using namespace std;

template <typename KEY, typename VALUE>
class HashTable
{
private:
	struct Node
	{
		KEY key;
		VALUE value;

		Node* next;
	};

	struct Bucket
	{
		int count;
		Bucket* head;
	};

	int capacity;
	int size;

	Bucket* bucket;

public:
	HashTable()
	{
		size = 0;
		capacity = 8;

		bucket = new Bucket[capacity];

		for (int i = 0; i < capacity; i++)
		{
			bucket[i].head = nullptr;
			bucket[i].count = 0;
		}
	}

	template <typename KEY>
	unsigned int hash_function(KEY key)
	{
		return (unsigned int)key % capacity;
	}
};

int main()
{
	HashTable<const char*, int> hashtable;

	cout << hashtable.hash_function("Bami's Cinder") << endl;

	return 0;
}