#include <iostream>
#include <stdexcept>

using namespace std;

class Node
{
    public:
        Node(int val);
        int value;
        Node* prev;
        Node* next;
};

Node::Node(int val) : value(val), next(nullptr), prev(nullptr){}

class List
{
    public:
        List();
        List(List &list);
        void push_front(int value);
        bool pop_front(int &value);
        void push_back(int value);
        bool pop_back(int &value);
        int at(int index);
        void insert_at(int index, int value);
        void remove_at(int index);
        int size();
        Node* Head();
        Node* Tail();
    private:
        Node* head;
        Node* tail;
};

List::List() : head(nullptr), tail(nullptr){}

List::List(List &list) : List()
{
    head = list.Head();
    tail = list.Tail();
}

Node* List::Head()
{
    return head;
}

Node* List::Tail()
{
    return tail;
}

void List::push_front(int value)
{
    Node* new_head = new Node(value);
    new_head->next = head;

    if(head == nullptr)
        tail = new_head;
    else head->prev = new_head;

    head=new_head;
}

bool List::pop_front(int &value)
{
    if(head == nullptr)
        return false;

    value = head->value;

    if(tail == head)
        tail = nullptr;

    head = head->next;
    return true;
}

void List::push_back(int value)
{
    if(head != nullptr)
    {
        Node* new_tail = new Node(value);
        tail->next = new_tail;
        new_tail->prev = tail;
        tail = new_tail;
    }
    else push_front(value);
}

bool List::pop_back(int &value)
{
    if(tail == nullptr)
        return false;

    value = tail->value;

    if(tail == head)
        head = nullptr;

    tail = tail->prev;
    return true;
}

int List::at(int index)
{
    int i = 0;
    for(Node* iter = head; iter != nullptr; iter = iter->next)
        if(i++ == index)
            return iter->value;

    throw invalid_argument("Invalid index value (less than 0 or bigger than size of list)");
}

void List::insert_at(int index, int value)
{
    Node* new_node = new Node(value);

    int i = 0;
    for(Node* iter = head; iter != nullptr; iter = iter->next)
        if(i++ == index)
        {
            new_node->prev = iter->prev;

            if(iter->prev != nullptr)
                iter->prev->next = new_node;

            new_node->next = iter;
            iter->prev = new_node;
            return;
        }

    throw invalid_argument("Invalid index value (less than 0 or bigger than size of list)");
}

void List::remove_at(int index)
{
    int i = 0;
    for(Node* iter = head; iter != nullptr; iter = iter->next)
        if(i++ == index)
        {
            if(iter->prev != nullptr)
                iter->prev->next = iter->next;
            if(iter->next != nullptr)
                iter->next->prev = iter->prev;
            return;
        }

    throw invalid_argument("Invalid index value (less than 0 or bigger than size of list)");
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

    cout << "Push back" << endl;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    int value = 0;

    cout << endl << "Size is: " << list.size() << endl;
    cout << "Element at 3 is: " << list.at(2) << endl << endl;

    while(list.pop_back(value))
        cout << "Pop back, value is: " << value << endl;

    cout << endl << "Push back" << endl;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    while(list.pop_front(value))
        cout << "Pop front, value is: " << value << endl;

    cout << endl << "Push front" << endl;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);

    while(list.pop_front(value))
        cout << "Pop front, value is: " << value << endl;

    cout << endl << "Push back" << endl;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    cout << "Insert at 3 value \"5\"" << endl;
    list.insert_at(2, 5);

    while(list.pop_front(value))
        cout << "Pop front, value is: " << value << endl;

    cout << endl << "Push back" << endl;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    cout << endl << "Size is: " << list.size() << endl;
    cout << "Remove at 4" << endl;
    list.remove_at(3);
    cout << "Size is: " << list.size() << endl;

    while(list.pop_front(value))
        cout << "Pop front, value is: " << value << endl;

    cout << endl << "Push back" << endl;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    cout << "Create new list from existing list:" << endl;
    List list2(list);

    cout << "Pop front for list:" << endl;

    while(list.pop_front(value))
        cout << "Pop front, value is: " << value << endl;

    cout << endl << "Pop front for list2:" << endl;

    while(list2.pop_front(value))
        cout << "Pop front, value is: " << value << endl;
    return 0;
}
