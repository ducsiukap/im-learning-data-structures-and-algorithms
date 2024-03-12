#include <iostream>
//* sd binary search tree
using namespace std;
typedef long long ll;
struct Node
{
    ll data;
    Node *p, *left, *right;
    Node(ll &val) : data(val), p(nullptr), left(nullptr), right(nullptr) {}
};

typedef Node *node;
class bst
{
private:
    node head;
    int len;
    void transplant(node u, node v)
    {
        if (u == head)
            head = v;
        else if (u->p->left == u)
            u->p->left = v;
        else
            u->p->right = v;
        if (v != nullptr)
            v->p = u->p;
    }
    node minimum(node tmp)
    {
        while (tmp->left != nullptr)
        {
            if (tmp == nullptr)
            {
                cout << "YES";
                return nullptr;
            }
            tmp = tmp->left;
        }
        return tmp;
    }

public:
    bst() : len(0), head(nullptr) {}
    ~bst() {}
    // getsize
    int Size() { return len; }
    // insert
    void push(ll &val)
    {
        ++len;
        if (head == nullptr)
        {
            head = new Node(val);
            return;
        }
        node newNode = new Node(val);
        node par = nullptr, cur = head;
        while (cur != nullptr)
        {
            par = cur;
            if (val < cur->data)
                cur = cur->left;
            else
                cur = cur->right;
        }
        newNode->p = par;
        if (val < par->data)
            par->left = newNode;
        else
            par->right = newNode;
    }
    // show the minimum element in tree and remove it
    int pop()
    {
        --len;
        node tmp = minimum(head);
        transplant(tmp, tmp->right);
        return tmp->data;
    }
};

void input(bst &ds, int &n)
{
    ll x;
    cin >> n;
    do
    {
        cin >> x;
        ds.push(x);
    } while (--n);
}

void output(bst &ds)
{
    ll res, tmp;
    res = 0;
    while (ds.Size() > 1)
    {
        tmp = ds.pop();
        tmp += ds.pop();
        res += tmp;
        ds.push(tmp);
    }
    cout << res << '\n';
    ds.pop();
    ds.~bst(); // free memory
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    bst ds;
    cin >> t;
    do
    {
        input(ds, n);
        output(ds);
    } while (--t);
    return 0;
}