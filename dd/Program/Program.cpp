#include <iostream>

using namespace std;

template <typename T>
class List
{
private:
	struct Node
	{
		T data;
		Node* next;
	};

	int size;
	Node* head;
public:
	List()
	{
		size = 0;
		head = nullptr;
	}

	void push_back(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = newNode;

			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;

			head->next = newNode;

			head = newNode;
		}

		size++;

	}

	void pop_back()
	{
		Node* deleteNode = head;
		
		if (size == 1)
		{
			deleteNode = nullptr;
		}
		else if (size == 0)
		{
			cout << "linked list is empty" << endl;
		}
		else
		{
			Node* currentNode = head;
				
			for (int i = 0; i <= size; i++)
			{
				currentNode = head->next;
			}

			head = currentNode;
			
			deleteNode = nullptr;
		}

		size--;

	}

};

int main()
{
	List<int> list;

	list.push_back(10);
	list.push_back(20);
	list.push_back(30);

	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.pop_back();
}