#include <iostream>

using namespace std;

template <typename T>
class Stack
{
private:
	int highset;
	int capacity;

	T* container;
public:
	Stack()
	{
		highset = -1;
		capacity = 0;

		container = nullptr;
	}

	void resize(int newSize)
	{
		capacity = newSize;

		T* temporary = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			temporary[i] = NULL;
		}
	}
};

int main()
{
	Stack<int> stack;

	return 0;
}