#include <iostream>

#define SIZE 5

using namespace std;

template <typename T>
class Queue
{
private:
	int front;
	int rear;

	T container[SIZE];
public:
	Queue()
	{
		front = 0;
		rear = 0;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}

	void push(T data)
	{
		if (rear >= SIZE)
		{
			cout << "linear queue overflow" << endl;
		}
		else
		{
			container[rear++] = data;
		}
	}

	const bool& empty()
	{
		return front == NULL;
	}

	const T& peek()
	{
		return container[front];
	}

	void pop()
	{
		if (empty())
		{
			cout << "linear queue is empty" << endl;
		}
		else
		{
			container[front++] = NULL;
		}
	}

	const int& size()
	{
		return SIZE;
	}

};

int main()
{
	Queue<int> queue;

	queue.push(10);
	queue.push(20);
	queue.push(30);
	queue.push(40);
	queue.push(50);

	while (!queue.empty())
	{
		cout << queue.peek() << endl;

		queue.pop();
	}



	return 0;
}