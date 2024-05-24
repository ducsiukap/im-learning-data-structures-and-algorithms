// * Code by Ducsjukapvippro
// * dont cry bae =))
// * neu ngay mai khong den thi sao?

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

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

bool dfs(vt(vt(int)) & ke, vt(bool) & unused, int &u, int &par)
{
    unused[u] = false;

    for (int &t : ke[u])
    {
        if (unused[t])
            return dfs(ke, unused, t, u);
        else if (u != par)
            return true;
    }

    return false;
}
bool ktct(vt(vt(int)) & ke, int &n)
{
    vt(bool) unused(n + 1, true);

    fe(i, 1, n) if (unused[i]) if (dfs(ke, unused, n, i)) return true;
    return false;
}

void __vippro__()
{
    int n, ne;
    cin >> n >> ne;

    vt(vt(int)) ke(n + 1);

    fr(i, 0, ne)
    {
        int u, v;
        cin >> u >> v;
        ke[u].pb(v);
        ke[v].pb(u);
    }

    cout << (ktct(ke, n) ? "YES" : "NO");
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
