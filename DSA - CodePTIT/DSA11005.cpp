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
#define in(x, n) fr(i, 0, n) cin >> x[i]
#define out(x, n, sep) fr(i, 0, n) cout << x[i] << sep
#define reset(x, n, value) fr(i, 0, n) x[i] = value

struct Node
{
    int info;
    Node *left, *right;
    Node(int &data) : info(data), left(nullptr), right(nullptr) {}
};

typedef Node *node;

void build_tree(node &root, int in[], int lev[], int st, int en, int &n)
{
    if (st > en)
        return;

    root = new Node(lev[0]);

    int root_pos = st;
    fe(i, st + 1, en) if (in[i] == lev[0])
    {
        root_pos = i;
        break;
    }

    // re-level
    int left_level[1005], right_level[1005];
    int left_index = 0, right_index = 0;
    fr(i, 1, n)
    {
        int k = st;
        while (in[k] != lev[i])
            ++k;
        if (k < root_pos)
        {
            left_level[left_index] = lev[i];
            ++left_index;
        }
        else
        {
            right_level[right_index] = lev[i];
            ++right_index;
        }
    }

    build_tree(root->left, in, left_level, st, root_pos - 1, left_index);
    build_tree(root->right, in, right_level, root_pos + 1, en, right_index);
}

void postOrder(node root)
{
    if (root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->info << ' ';
}
void __vippro__()
{
    int in[1005], lev[1005], n;
    cin >> n;
    in(in, n);
    in(lev, n);

    node root = nullptr;
    build_tree(root, in, lev, 0, n - 1, n);
    postOrder(root);
    cout << '\n';
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
