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
    Node(int &val) : data(val), next(nullptr){};
};
typedef Node *node;

class stackk
{
private:
    node head;
    int len;

public:
    stackk() : len(0), head(nullptr) {}
    void push(int &val) // push at head
    {
        node newNode = new Node(val);
        if (len)
            newNode->next = head;
        head = newNode;
        ++len;
    }
    void pop() // pop at head
    {
        if (len)
        {
            node tmp = head;
            head = head->next;
            delete tmp;
            --len;
        }
    }
    void top()
    {
        if (head == nullptr)
            cout << "NONE\n";
        else
            cout << head->data << '\n';
    }
};

void __vippro__()
{
    stackk s;
    string str;
    int qs, x;
    cin >> qs;
    while (qs--)
    {
        cin >> str;
        if (str == "PUSH")
        {
            cin >> x;
            s.push(x);
        }
        else if (str == "POP")
            s.pop();
        else
            s.top();
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