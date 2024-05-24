// * Code by Ducsjukapvippro
// * dont cry bae =))
// * neu ngay mai khong den thi sao?

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
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

vt(int) bfs(vt(vt(int)) & ke, int &n, int &u)
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
    int n, ne, u;
    cin >> n >> ne >> u;

    vt(vt(int)) ke(n + 1);
    fr(i, 0, ne)
    {
        int a, b;
        cin >> a >> b;
        ke[a].pb(b);
        ke[b].pb(a);
    }

    vt(int) prev = bfs(ke, n, u);

    fe(i, 1, n)
    {
        if (i == u)
            continue;
        if (prev[i] == 0)
            cout << "No path\n";
        else
        {
            stack<int> path;
            int en = i;
            while (en != u)
            {
                path.push(en);
                en = prev[en];
            }

            cout << u << ' ';
            while (!path.empty())
            {
                cout << path.top() << ' ';
                path.pop();
            }

            cout << '\n';
        }
    }
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
