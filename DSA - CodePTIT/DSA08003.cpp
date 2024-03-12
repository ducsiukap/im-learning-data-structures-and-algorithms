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
    Node *next, *prev;
    Node(int &val) : data(val), next(nullptr), prev(nullptr) {}
};

typedef Node *node;

class QUEUE
{
private:
    int queue_size;
    node queue_head;
    node queue_tail;

public:
    QUEUE() : queue_size(0), queue_head(nullptr), queue_tail(nullptr) {}
    void push(char &c, int &val)
    {
        if (queue_size == 0)
            queue_head = queue_tail = new Node(val);
        else
        {
            node newNode = new Node(val);
            if (c == 'F')
            {
                newNode->next = queue_head;
                queue_head->prev = newNode;
                queue_head = newNode;
            }
            else
            {
                queue_tail->next = newNode;
                newNode->prev = queue_tail;
                queue_tail = newNode;
            }
        }
        ++queue_size;
    }
    void pop(char &c)
    {
        if (queue_size)
        {
            if (c == 'F')
            {
                node tmp = queue_head;
                queue_head = queue_head->next;
                delete tmp;
            }
            else
            {
                node tmp = queue_tail;
                queue_tail = queue_tail->prev;
                delete tmp;
            }
            --queue_size;
        }
    }
    void top(char &c)
    {
        if (queue_size)
        {
            if (c == 'F')
                cout << queue_head->data;
            else
                cout << queue_tail->data;
            cout << '\n';
        }
        else
            cout << "NONE\n";
    }
};

void __vippro__()
{
    QUEUE q;
    int qs, x;
    string ops;
    cin >> qs;
    do
    {
        cin >> ops;
        if (ops[1] == 'U')
        {
            cin >> x;
            q.push(ops[4], x);
        }
        else if (ops[1] == 'O')
            q.pop(ops[3]);
        else
            q.top(ops[5]);
    } while (--qs);
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