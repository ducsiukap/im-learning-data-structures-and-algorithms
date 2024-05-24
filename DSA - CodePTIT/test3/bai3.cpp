// * Code by Ducsjukapvippro
// * dont cry bae =))
// * neu ngay mai khong den thi sao?

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

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
#define in(x, n) fr(itr, 0, n) cin >> x[itr]
#define out(x, n, sep) fr(itr, 0, n) cout << x[itr] << sep
#define reset(x, n, value) fr(itr, 0, n) x[itr] = value

struct Node
{
    int data;
    Node *left, *right;
    bool ok;
    Node(int &val) : data(val), left(nullptr), right(nullptr), ok(true) {}
};

typedef Node *node;

void them(vt(node) & tree, int &par, int &data, char &c)
{
    fr(i, 0, sz(tree))
    {
        if (tree[i]->data == par)
        {
            node newNode = new Node(data);
            if (c == 'L')
                tree[i]->left = newNode;
            else
                tree[i]->right = newNode;

            if (tree[i]->left && tree[i]->right)
                tree[i]->ok = true;
            else if (tree[i]->left == nullptr && tree[i]->right == nullptr)
                tree[i]->ok = true;

            if (tree[i]->left && !(tree[i]->right))
                tree[i]->ok = false;
            if (tree[i]->right && !(tree[i]->left))
                tree[i]->ok = false;

            tree.push_back(newNode);
            return;
        }
    }
}

void __vippro__()
{
    int n;
    cin >> n;

    int a, b;
    char c;
    cin >> a >> b >> c;

    vt(node) tree;
    tree.push_back(new Node(a));
    them(tree, a, b, c);

    fr(i, 1, n)
    {
        cin >> a >> b >> c;
        them(tree, a, b, c);
    }

    fr(i, 0, sz(tree))
    {
        if (tree[i]->ok == false)
        {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES\n";
}

__ducsjukap__
{
    // faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
