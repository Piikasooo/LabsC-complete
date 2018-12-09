#include <iostream>

using namespace std;

class Node
{
    public:
        Node(int val);
        int	value;
        Node* next;
};

Node::Node(int val)
{
	value = val;
	next = nullptr;
}

class List
{
    public:
        List();
        List(List *other);
        void push_front(int	value);
        bool pop_front(int value);
        void push_back(int value);
        bool pop_back(int value);
        int at(int index);
        void insert_at(int index, int value);
        void remove_at(int index);
        int	size();
        Node* get(int index);
    private:
        Node* head;
        Node* tail;
};

int List::size()
{
	Node* temp = head;
	int result = 0;
	while (temp != nullptr)
	{
		result++;
		temp = temp->next;
	}
	return result;
}

List::List()
{
	head = nullptr;
	tail = nullptr;
}

Node* List::get(int index)
{
	Node* result = this->head;
	while (index > 0)
	{
		index--;
		result = result->next;
	}
	return result;
}

List::List(List *other)
{
	if (other->head != nullptr)
	{
		head = new Node(other->head->value);
		Node *temp = other->head;
		Node *prev = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
			tail = new Node(temp->value);
			prev->next = tail;
			prev = tail;
		}
	}
	else
	{
		List();
	}
}

void List::push_front(int value)
{
	Node* newhead = new Node(value);
	newhead->next = this->head;
	this->head = newhead;
	if (size() == 1) this->tail = this->head;
}

void List::push_back(int value)
{
	Node* newtail = new Node(value);
	this->tail->next = newtail;
	this->tail = newtail;
	if (this->size() == 0) this->head = this->tail;
}

bool List::pop_front(int value)
{
	if (this->head == nullptr) return false;
	Node* temp = this->head->next;
	delete this->head;
	this->head = temp;
	return true;
}

bool List::pop_back(int value)
{
	if (this->tail == nullptr) return false;
	delete this->tail;
	this->tail = get(this->size() - 1);
	this->tail->next = nullptr;
	return true;
}

int List::at(int index)
{
	return this->get(index)->value;
}

void List::insert_at(int index, int value)
{
	Node* temp = this->get(index - 1);
	Node* newnode = new Node(value);
	newnode->next = temp->next;
	temp->next = newnode;
}

void List::remove_at(int index)
{
	if (index == 0) this->pop_front(0);
	else
	{
		Node* temp = this->get(index - 1);
		Node* toremove = this->get(index);
		temp->next = toremove->next;
		delete toremove;
	}
}

void printList(List list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << "list[" << i << "] == " << list.at(i) << endl;
	}
}
int main()
{
	List list1;
	list1.push_front(1);
	list1.push_front(2);
	list1.push_front(3);
	list1.push_front(4);
	cout << "list1" << endl;
	printList(list1);
	cout << endl;

	List list2 = List(&list1);
	cout << "list2" << endl;
	printList(list2);
	cout << endl;

	list1.insert_at(1, 6);
	list2.remove_at(2);

	cout << "list1" << endl;
	printList(list1);
	cout << endl << "list2" << endl;
	printList(list2);
	cout << endl;

    return 0;
}
