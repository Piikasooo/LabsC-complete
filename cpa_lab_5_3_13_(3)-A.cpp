#include <iostream>

using namespace std;

class Node
{
    public:
        Node(int val);
        int value;
        Node* next;
};

Node::Node(int val) : value(val), next(nullptr) {}

class List {
    public:
        List();
        void push_front(int value);
        bool pop_front(int &value);
        int size();
    private:
        Node* head;
        Node* tail;
};

List::List() : head(nullptr), tail(nullptr) {}

void List::push_front(int value)
{
	Node* new_head = new Node(value);
	new_head->next = head;

	if (head == nullptr)
		tail = new_head;

	head = new_head;
}

bool List::pop_front(int &value)
{
	if (head == nullptr)
		return false;

	value = (*head).value;
	head = (*head).next;
	return true;
}

int List::size()
{
	int i = 0;
	for (Node* iter = head; iter != nullptr; iter = iter->next, ++i);
	return i;
}

int main()
{
	List list;
	for (int i = 0; i <= 5; i++)
	{
		list.push_front(i);
		cout << "pushed " << i << ", size:" << list.size() << endl;
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		int value = i;
		list.pop_front(i);
		cout << "popped " << i << ", size:" << list.size() << endl;
		i = value;
	}
	return 0;
}
