#include <iostream>

using namespace std;

class Node
{
public:
    Node(int val);
    int value;
    Node* next;
};

Node::Node(int val) : value(val), next(nullptr){}

class List
{
public:
    List();
    void push_front(int value);
    bool pop_front(int &value);
    void push_back(int value);
    bool pop_back(int &value);
    int size();
private:
    Node* head;
    Node* tail;
};

List::List() : head(nullptr), tail(nullptr){}

void List::push_front(int value)
{
    Node* new_head = new Node(value);
    new_head->next = head;

    if(head == nullptr)
        tail = new_head;

    head=new_head;
}

bool List::pop_front(int &value)
{
    if(head)
    {   value = head->value;
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return true;
    }
    return false;
}

void List::push_back(int value)
{
    if(head != nullptr)
    {
        Node* new_tail = new Node(value);
        tail->next = new_tail;
        tail = new_tail;
    }
    else push_front(value);
}

bool List::pop_back(int &value)
{
    if (!head)
        return false;
    if (head == tail)
    {
        value = head->value;
        delete head;
        head = NULL;
        tail = NULL;
        return true;
    }
    value = tail->value;
    Node *current = head;
    while ( current->next != tail )
    {
        current = current->next;
    }

    delete tail;
    tail = current;
    tail->next = NULL;
    return true;
}

int List::size()
{
    int i = 0;
    for(Node* iter = head; iter != nullptr; iter = iter->next, ++i);
    return i;
}

int main()
{
    List list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    int value = 0;
    while (list.pop_back(value))
    {
        cout << value << endl;
    }
    return 0;
}
