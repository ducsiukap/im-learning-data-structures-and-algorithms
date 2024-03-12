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
    int pesticide;
    Node *next;
    Node(int &value) : pesticide(value), next(nullptr) {}
};

typedef Node *node;

class Stack
{
public:
    node head;
    Stack() : head(nullptr){};
    void push(int &val)
    {
        node newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void pop(node &tmp)
    {
        if (tmp == head)
            head = head->next;
        else
        {
            node tmp2 = head;
            while (tmp2->next != tmp)
                tmp2 = tmp2->next;
            cout << 1 << '\n';
            tmp2->next = tmp2->next->next;
        }
    }
    bool noPlantdies()
    {
        node tmp = head, p(nullptr);
        bool ok = 1;
        while (tmp->next)
        {
            if (tmp->pesticide > tmp->next->pesticide)
            {
                if (p == nullptr)
                {
                    head = head->next;
                    tmp = head;
                }
                else
                {
                    p->next = p->next->next;
                    tmp = p;
                }
                ok = 0;
            }
            else
                p = tmp;
            tmp = tmp->next;
        }
        return ok;
    }
};

void __vippro__()
{
    int n, x, res;
    Stack s;
    cin >> n;
    while (n--)
    {
        cin >> x;
        s.push(x);
    }
    res = 0;
    while (!s.noPlantdies())
        ++res;
    cout << res << '\n';
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