#include <iostream>

using namespace std;

template <typename T>
class Vector
{
private:
	T* pointer;

	int count;
	int capacity;
public:
	Vector()
	{
		pointer = nullptr;
		count = 0;
		capacity = 0;
	}

	void resize(int newSize)
	{
		capacity = newSize;

		T* temporary[capacity] = new T;

		for (int i = 0; i < capacity; i++)
		{
			temporary[i] = nullptr;
		}





	}

};

int main()
{
	Vector<int> vector;

	return 0;
}