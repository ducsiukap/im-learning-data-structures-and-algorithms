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
    string data;
    Node *left, *right;

    Node(string &in4) : data(in4), left(nullptr), right(nullptr) {}
};

int to_int(string &s)
{
    int num = 0;
    if (s[0] == '-')
    {
        fr(i, 1, s.size())
            num = num * 10 + s[i] - '0';
        num *= -1;
    }
    else
        fr(i, 0, s.size())
            num = num * 10 + s[i] - '0';

    return num;
}

// ll calculator(Node *root)
// {
//     if (root)
//     {
//         if (!root->left && !root->right)
//             return to_int(root->data);

//         ll l = calculator(root->left);
//         ll r = calculator(root->right);
//         if (root->data == "+")
//             return l + r;
//         if (root->data == "-")
//             return l - r;
//         if (root->data == "*")
//             return l * r;
//         if (root->data == "/")
//             return l / r;
//     }

//     return 0;
// }

// void build_tree(Node *&root, vt(string) & v, int i, int n)
// {
//     if (i >= n)
//         return;

//     root = new Node(v[i]);
//     build_tree(root->left, v, 2 * i + 1, n);
//     build_tree(root->right, v, 2 * i + 2, n);
// }

// cay day du tu tren xuong, tu trai qua phai => n = 2^x
ll calc(vt(string) & v, int i, int n)
{
    if (i >= n)
        return 0;

    ll left = calc(v, 2 * i + 1, n);
    ll right = calc(v, 2 * i + 2, n);
    if (v[i] == "+")
        return left + right;
    if (v[i] == "-")
        return left - right;
    if (v[i] == "*")
        return left * right;
    if (v[i] == "/")
        return left / right;

    return to_int(v[i]);
}

void __vippro__()
{
    int n;
    cin >> n;
    vt(string) v(n);
    for (string &s : v)
        cin >> s;

    // Node *root = nullptr;
    // build_tree(root, v, 0, v.size());
    // cout << calculator(root) << '\n';
    cout << calc(v, 0, n) << '\n';
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
