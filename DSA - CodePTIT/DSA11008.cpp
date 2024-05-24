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
#define node Node *

struct Node
{
    int info, level;
    node left;
    node right;
    Node(int &data, int lev) : level(lev), info(data), left(nullptr), right(nullptr) {}
};

void expand_tree(vt(node) & tree, int u, int v, char c)
{
    node par = nullptr;
    for (node &x : tree)
        if (x->info == u)
        {
            par = x;
            break;
        }
    if (par)
    {
        node newNode = new Node(v, par->level + 1);
        if (c == 'L')
            par->left = newNode;
        else
            par->right = newNode;
        tree.push_back(newNode);
    }
}

bool check_leaf_level(node root)
{
    node tmp = root;
    while (tmp->left)
        tmp = tmp->left;

    int leaf_level = tmp->level;
    queue<node> q;
    q.push(root);
    while (!q.empty())
    {
        if (!q.front())
        {
            q.pop();
            continue;
        }

        tmp = q.front();
        q.pop();

        if (!tmp->left && !tmp->right)
        {
            if (tmp->level != leaf_level)
                return false;
        }
        q.push(tmp->left);
        q.push(tmp->right);
    }
    return true;
}

void __vippro__()
{
    int n, a, b;
    char c;
    cin >> n >> a >> b >> c;

    node root = new Node(a, 0);
    vt(node) tree;
    tree.push_back(root);
    expand_tree(tree, a, b, c);

    fr(i, 1, n)
    {
        cin >> a >> b >> c;
        expand_tree(tree, a, b, c);
    }

    cout << check_leaf_level(root) << '\n';
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
