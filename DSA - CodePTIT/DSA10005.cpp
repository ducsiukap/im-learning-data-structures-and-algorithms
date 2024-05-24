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
#define in(x, n) fr(itr, 0, n) cin >> x[itr]
#define out(x, n, sep) fr(itr, 0, n) cout << x[itr] << sep
#define reset(x, n, value) fr(itr, 0, n) x[itr] = value

bool bfs(vt(vt(int)) & ke, int &n, int &u)
{
    vt(bool) unused(n + 1, true);

    queue<int> q;
    q.push(u);
    unused[u] = false;

    int cnt = 0;
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        ++cnt;

        for (int &t : ke[s])
            if (unused[t])
            {
                q.push(t);
                unused[t] = false;
            }
    }

    return cnt == n;
}

bool have_EC(vt(vt(int)) & ke, vt(int) & deg, int &n)
{
    fe(i, 1, n) if (!bfs(ke, n, i)) return false;

    fe(i, 1, n) if (deg[i] != 0) return false;

    return true;
}

void __vippro__()
{
    int n, ne;
    cin >> n >> ne;

    vt(vt(int)) ke(n + 1);
    vt(int) deg(n + 1, 0);

    fr(i, 0, ne)
    {
        int u, v;
        cin >> u >> v;
        ke[u].push_back(v);
        ++deg[u];
        --deg[v];
    }

    cout << have_EC(ke, deg, n) << '\n';
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
