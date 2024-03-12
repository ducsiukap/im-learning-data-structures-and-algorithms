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
            tmp = tmp->next;
        tmp->next = new Node(val);
    }
    // delete a node
    void delete_node(int &val)
    {
        node tmp = head;
        while (tmp != nullptr)
        {
            if (tmp->data != val)
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
    cin >> sz; // nhap phan tu de xoa
    // xoa va hien thi list
    ds.delete_node(sz);
    system("pause");
}