#include <iostream>

using namespace std;

template <typename T>
class Graph
{
private:
	struct Node
	{
		T data;
		Node* link;
	};

	int count;
	int size;
	int capacity;

	T* vertex;
	int** matrix;

public:
	Graph(T data, Node* link)
	{

	}
};

int main()
{

	return 0;
}
