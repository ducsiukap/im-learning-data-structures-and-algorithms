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
    Node(int val) : data(val), next(nullptr) {}
};

typedef Node *node;

class stack_ // LIFO
{
private:
    node head;
    int length;

public:
    stack_() : head(nullptr), length(0) {}
    // insert at head
    void push(int val)
    {
        ++length;
        if (head == nullptr)
            head = new Node(val);
        else
        {
            node newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }
    }
    // delete
    void pop()
    {
        if (head == nullptr)
            return;
        --length;
        node tmp = head;
        head = head->next;
        delete tmp;
    }
    // getmax
    int getMax()
    {
        node tmp = head->next;
        int Max = head->data;
        while (tmp)
        {
            Max = max(Max, tmp->data);
            tmp = tmp->next;
        }
        return Max;
    }
    // empty()
    bool Empty() { return length == 0; }
};

void __vippro__()
{
    stack_ s;
    int qs, opt, x;
    cin >> qs;
    while (qs--)
    {
        cin >> opt;
        switch (opt)
        {
        case 1:
            cin >> x;
            s.push(x);
            break;
        case 2:
            s.pop();
            break;
        default:
            cout << s.getMax() << '\n';
            break;
        }
    }
}

__ducsjukap__()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    int T;
    cin >> T;
    dr(T, T, 0)
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro