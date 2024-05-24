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

void bfs(vt(vt(int)) & ke, int &n, int &u)
{
    vt(bool) unused(n + 1, true);
    queue<int> q;

    q.push(u);
    unused[u] = false;

    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        cout << s << ' ';

        for (int &t : ke[s])
            if (unused[t])
            {
                q.push(t);
                unused[t] = false;
            }
    }

    cout << '\n';
}

void __vippro__()
{
    int n, ne, s;
    cin >> n >> ne >> s;

    vt(vt(int)) ke(n + 1);
    fr(i, 0, ne)
    {
        int a, b;
        cin >> a >> b;
        ke[a].push_back(b);
    }

    bfs(ke, n, s);
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
