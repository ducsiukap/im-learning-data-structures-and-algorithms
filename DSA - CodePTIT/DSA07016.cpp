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
class my_stack
{
private:
    node head, tail;

public:
    my_stack() : head(nullptr), tail(nullptr) {}
    void push_head(int val)
    {
        if (head == nullptr)
            head = tail = new Node(val);
        else
        {
            node newNode = new Node(val);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void push_tail(int val, int pos)
    {
        if (head == nullptr)
            head = tail = new Node(val);
        else if (pos == -1)
        {
            node newNode = new Node(val);
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            node newNode = new Node(tail->data);
            node tmp = tail;
            while (tmp && pos)
            {
                ++tmp->data;
                tmp = tmp->prev;
                --pos;
            }
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void show_stack()
    {
        node tmp = head;
        while (tmp)
        {
            cout << tmp->data;
            tmp = tmp->next;
        }
        cout << '\n';
    }
};

void __vippro__()
{
    string s;
    my_stack st;
    int head_value = 1, i, cnt;
    st.push_head(head_value);
    cin >> s;
    i = 0;
    while (s[i] == 'D')
    {
        ++head_value;
        st.push_head(head_value);
        ++i;
    }
    while (i < s.size())
    {
        if (s[i] == 'D')
        {
            ++cnt;
            st.push_tail(-1, cnt);
        }
        else
        {
            cnt = 0;
            st.push_tail(head_value + 1, -1);
        }
        ++head_value;
        ++i;
    }
    st.show_stack();
}

__ducsjukap__()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    dr(T, T, 0)
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro