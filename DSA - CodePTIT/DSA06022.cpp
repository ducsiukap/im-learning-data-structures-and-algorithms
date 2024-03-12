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
    Node *p, *l, *r;
    Node(int &val) : data(val) { p = l = r = nullptr; }
};
typedef Node *node;

class binary_search_tree_
{
public:
    node tree_root;
    int tree_size;
    binary_search_tree_() : tree_size(0), tree_root(nullptr) {}

    void push(int &val)
    {
        node newNode = new Node(val);
        if (tree_size)
        {
            node par = nullptr;
            node cur = tree_root;
            while (cur)
            {
                par = cur;

                if (cur->data == val)
                    break;
                if (val < cur->data)
                    cur = cur->l;
                else
                    cur = cur->r;
            }
            if (val < par->data)
            {
                newNode->p = par;
                par->l = newNode;
            }
            else if (val > par->data)
            {
                newNode->p = par;
                par->r = newNode;
            }
        }
        else
            tree_root = newNode;
        ++tree_size;
    }
    void traversal(node tmp, vector<int> &v)
    {
        if (tmp == nullptr)
            return;
        traversal(tmp->l, v);
        v.push_back(tmp->data);
        traversal(tmp->r, v);
    }
};

void __vippro__()
{
    int n, x;
    cin >> n;
    binary_search_tree_ btree;
    while (n--)
    {
        cin >> x;
        btree.push(x);
    }
    vector<int> v;
    btree.traversal(btree.tree_root, v);
    if (v.size() == 1)
        cout << "-1\n";
    else
        cout << v[0] << ' ' << v[1] << '\n';
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