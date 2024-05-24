// * Code by Ducsjukapvippro
// * dont cry bae =))
// * neu ngay mai khong den thi sao?

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;

#define __ducsjukap__ int main()
#define faster()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define run() \
    int T;    \
    cin >> T; \
    while (T--)
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define fi first
#define se second
#define pb(a) push_back(a)
#define fr(i, a, b) for (int i = a; i < b; ++i)
#define fe(i, a, b) for (int i = a; i <= b; ++i)
#define dr(i, a, b) for (int i = a; i > b; --i)
#define de(i, a, b) for (int i = a; i >= b; --i)
#define in(x, n) fr(i, 0, n) cin >> x[i]
#define out(x, n, sep) fr(i, 0, n) cout << x[i] << sep
#define reset(x, n, value) fr(i, 0, n) x[i] = value

struct Node
{
    int data;
    Node *l, *r;
    Node(int &info) : data(info), l(nullptr), r(nullptr) {}
};

typedef Node *node;

void expand_tree(vt(node) & tree, int &u, int &v, char &c)
{
    int pos = -1;
    fr(i, 0, tree.size()) if (tree[i]->data == u)
    {
        pos = i;
        break;
    }
    if (pos == -1)
        return;
    node newNode = new Node(v);
    if (c == 'L')
        tree[pos]->l = newNode;
    else
        tree[pos]->r = newNode;
    tree.push_back(newNode);
}

void level_traversal(node root)
{
    queue<node> q;
    q.push(root);
    while (!q.empty())
    {
        node x = q.front();
        q.pop();
        cout << x->data << ' ';
        if (x->l)
            q.push(x->l);
        if (x->r)
            q.push(x->r);
    }
    cout << '\n';
}
void __vippro__()
{
    int n, a, b;
    char c;
    cin >> n >> a >> b >> c;
    node root = new Node(a);

    // build tree
    vt(node) tree;
    tree.push_back(root);
    expand_tree(tree, a, b, c);
    fr(i, 1, n)
    {
        cin >> a >> b >> c;
        expand_tree(tree, a, b, c);
    }

    level_traversal(root);
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
