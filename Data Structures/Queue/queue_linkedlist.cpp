/*
Queue: FIFO
queue::front() -> head of queue -> select from here
queue::back() -> tail of queue -> push at here
queue::push(value) -> push at tail
queue::pop() -> delete at begin -> delete queue::front
queue::empty();
queue::size();
*/
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node() { next = nullptr; }
};

class stack
{
    node *head, *tail; // stack::front(), stack::back()
    int len;           // stack::size()
public:
    // constructor
    stack()
    {
        len = 0;
        head = tail = nullptr;
    }
    // make node
    node *make_node(int &n)
    {
        node *newNode = new node();
        newNode->data = n;
        return newNode;
    }
    // stack::push(value)
    void push(int n)
    {
        ++len; // increase size
        node *newNode = make_node(n);
        if (head == nullptr)
            head = tail = newNode; // if n is the first node
        else
        {
            // push at tail
            tail->next = newNode;
            tail = newNode;
        }
    }
    // stack::pop()
    void pop()
    {
        if (head == nullptr)
            cout << "Empty !\n";
        else
        {
            --len;
            head = head->next;
        }
    }
    // queue::front()
    int front() { return head->data; };
    // queue::back()
    int back() { return tail->data; }
    // empty
    bool empty() { return head == nullptr; }
    // size
    int size() { return len; }
};

int main()
{
    stack i_list;
    for (int i = 1; i <= 10; ++i)
        // queue::push(value)
        i_list.push(i);                           // push {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} to queue
    cout << "size : " << i_list.size() << '\n';   // queue::size()
    cout << "front : " << i_list.front() << '\n'; // queue::front()
    cout << "back : " << i_list.back() << "\n\n"; // queue::back()
    while (!i_list.empty())
    {
        cout << "Deleted " << i_list.front() << '\n';
        i_list.pop(); // queue::pop();
    }
    if (i_list.empty())
        cout << "Empty\n";
    i_list.pop();
    system("pause");
}
