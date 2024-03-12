/*
- stack : LIFO
- stack::top() -> head of stack
- stack::push() -> add new node to head of stack
- stack::pop() -> remove a node from head of stack
- stack::empty() -> check if stack is empty
- stack::size() -> number object in stack is available
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
    node *head;

public:
    stack() { head = nullptr; }
    // make node
    node *make_node(int &n)
    {
        node *newNode = new node();
        newNode->data = n;
        return newNode;
    }
    // push
    void push(int n)
    {
        node *newNode = make_node(n);
        newNode->next = head;
        head = newNode;
    }
    // pop
    void pop() { head = head->next; }
    // empty
    bool empty() { return (head == nullptr); }
    // top()
    int top() { return head->data; }
    // size()
    int size()
    {
        node *tmp = head;
        int cnt = 0;
        while (tmp != nullptr)
        {
            ++cnt;
            tmp = tmp->next;
        }
        return cnt;
    }
    // show list
    void show()
    {
        if (head == nullptr)
            cout << "empty!\n";
        else
        {
            node *tmp = head;
            while (tmp != nullptr)
            {
                cout << tmp->data << ' ';
                tmp = tmp->next;
            }
            cout << '\n';
        }
    }
};

int main()
{
    stack int_list;
    for (int i = 1; i < 10; ++i)
        // stack::push(n)
        int_list.push(i);                         // list: {9, 8, 7, 6, 5, 4, 3, 2, 1}
    cout << "size : " << int_list.size() << '\n'; // stack::size()
    int_list.show();                              // show the current list
    for (int i = 1; i < 10; ++i)
    {
        cout << "deleted " << int_list.top() << '\n'; // stack::top()
        int_list.pop();                               // stack::pop()
    }
    if (int_list.empty()) // stack::empty()
        cout << "\nList is empty!\n";
    system("pause");
}