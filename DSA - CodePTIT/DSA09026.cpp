// * Code by Ducsjukapvippro
// * dont cry bae =))
// * neu ngay mai khong den thi sao?

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
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

vt(int) dfs(vt(vt(int)) & ke, int &n, int &u)
{
    vt(bool) unused(n + 1, true);
    queue<int> q;
    vt(int) prev(n + 1, 0);

    q.push(u);
    unused[u] = false;
    prev[u] = u;

    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        for (int &t : ke[s])
            if (unused[t])
            {
                q.push(t);
                unused[t] = false;
                prev[t] = s;
            }
    }

    return prev;
}

void __vippro__()
{
    int n, ne, st, en;
    cin >> n >> ne >> st >> en;

    vt(vt(int)) ke(n + 1);
    fr(i, 0, ne)
    {
        int a, b;
        cin >> a >> b;
        ke[a].push_back(b);
    }

    vt(int) path = dfs(ke, n, st);

    if (path[en] == 0)
        cout << -1;
    else
    {
        stack<int> way;
        while (en != st)
        {
            way.push(en);
            en = path[en];
        }
        cout << st;
        while (!way.empty())
        {
            cout << ' ' << way.top();
            way.pop();
        }
    }
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
