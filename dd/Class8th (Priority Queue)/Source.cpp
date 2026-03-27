#include <iostream>

using namespace std;

template <typename T>
class PriorityQueue
{
private:
	int capacity;
	int index;

	T* container;
public:
	PriorityQueue()
	{
		capacity = 0;
		index = 0;

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

		for (int i = 0; i < index; i++)
		{
			temporary[i] = container[i];
		}

		delete[] container;

		container = temporary;
	}

	void push(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else if (index >= capacity)
		{
			resize(capacity * 2);
		}

		container[index++] = data;

		int child = index - 1;
		int parent = (child - 1) / 2;

		while (child > 0)
		{
			if (container[parent] < container[child])
			{
				swap(container[parent], container[child]);
			}

			child = parent;

			parent = (child - 1) / 2;
		}
	}

	void pop()
	{
		if (index > 0)
		{
			container[0] = container[--index];

			container[index] = NULL;

			int parent = 0;
			int child = parent * 2 + 1;

			while (child < index)
			{
				child = parent * 2 + 1;

				if (container[child] < container[child + 1])
				{
					child++;
				}

				if (container[child] < container[parent])
				{
					break;
				}
				else
				{
					swap(container[child], container[parent]);

					parent = child;
				}
			}
		}
		else
		{
			cout << "Priority queue is empty" << endl;
		}
	}

	const T& top()
	{
		return container[0];
	}

	const int& size()
	{
		return index;
	}

	const bool& empty()
	{
		return index <= 0;
	}

	~PriorityQueue()
	{
		delete[] container;
	}
};

int main()
{
	PriorityQueue<int> priorityQueue;

	priorityQueue.push(10);
	priorityQueue.push(50);
	priorityQueue.push(70);
	priorityQueue.push(5);
	priorityQueue.push(30);

	while (!priorityQueue.empty())
	{
		cout << priorityQueue.top() << endl;

		priorityQueue.pop();
	}

	priorityQueue.pop();

	cout << "Priority Queue is Size : " << priorityQueue.size() << endl;

	return 0;
}