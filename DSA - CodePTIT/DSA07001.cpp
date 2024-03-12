// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i <= b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

struct Node
{
    int data;
    Node *next;
    Node(int &Data) : data(Data), next(nullptr){};
};
typedef Node *node;
class Stack
{
private:
    node head;
    int len;

public:
    Stack() : len(0), head(nullptr) {}

    void push(int &val) // push at head :))
    {
        ++len;
        if (head == nullptr)
            head = new Node(val);
        else
        {
            node tmp = head;
            while (tmp->next)
                tmp = tmp->next;
            tmp->next = new Node(val);
        }
    }

    void pop() // pop at head :))))
    {
        if (head == nullptr)
            return;
        else
        {
            --len;
            node tmp = head;
            node prev = nullptr;
            while (tmp->next)
            {
                prev = tmp;
                tmp = tmp->next;
            }
            if (prev)
                prev->next = nullptr;
            else
                head = nullptr;
            delete tmp;
        }
    }

    void show() // show stack
    {
        if (head == nullptr)
            cout << "empty\n";
        else
        {
            node tmp = head;
            while (tmp)
            {
                cout << tmp->data << ' ';
                tmp = tmp->next;
            }
            cout << '\n';
        }
    }
};

void __vippro__()
{
    string s;
    Stack stack;
    int x;
    while (cin >> s)
    {
        if (s == "push")
        {
            cin >> x;
            stack.push(x);
        }
        else if (s == "pop")
            stack.pop();
        else
            stack.show();
    }
}

__ducsjukap__()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    // cin >> T;
    dr(T, 1, 0)
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro