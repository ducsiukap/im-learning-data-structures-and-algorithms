#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

typedef Node *node;

class list
{
private:
    node head;

public:
    list() : head(nullptr) {}
    // insert at end
    void push(int &val)
    {
        if (head == nullptr)
        {
            head = new Node(val);
            return;
        }
        node tmp = head;
        while (tmp->next != nullptr)
        {
            if (tmp->data == val)
                return;
            tmp = tmp->next;
        }
        if (tmp->data != val)
            tmp->next = new Node(val);
    }
    // show list
    void show()
    {
        node tmp = head;
        while (tmp != nullptr)
        {
            cout << tmp->data << ' ';
            tmp = tmp->next;
        }
        cout << '\n';
    }
};

int main()
{
    int sz, val;
    list ds;
    cin >> sz; // soluong phan tu
    while (sz)
    {
        --sz;
        cin >> val;
        ds.push(val); // them phan tu vao list
    }
    ds.show(); // show list
    system("pause");
}