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

bool ok;

void dfs(vt(vt(int)) & ke, vt(bool) & unused, int &n, int i, int dem)
{
    if (dem == n)
    {
        ok = 1;
        return;
    }
    if (ok)
        return;

    for (int &v : ke[i])
        if (unused[v])
        {
            unused[v] = false;
            dfs(ke, unused, n, v, dem + 1);
            unused[v] = true;
        }
}

bool check(vt(vt(int)) & ke, int &n)
{
    fe(i, 1, n)
    {
        vt(bool) unused(n + 1, 1);
        unused[i] = false;
        dfs(ke, unused, n, i, 1);
        if (ok)
            return true;
    }

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

    ok = 0;
    cout << check(ke, n) << '\n';
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
