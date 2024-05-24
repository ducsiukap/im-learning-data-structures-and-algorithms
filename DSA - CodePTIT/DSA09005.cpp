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

void bfs(vt(vt(int)) & v, int &n, int &u)
{
    vt(bool) check(n + 1, false);
    queue<int> q;
    q.push(u);
    check[u] = true;

    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        cout << s << ' ';
        fe(i, 1, n) if (v[s][i] && !check[i])
        {
            q.push(i);
            check[i] = true;
        }
    }
    cout << '\n';
}

void __vippro__()
{
    int n, e, u;
    cin >> n >> e >> u;

    vt(vt(int)) v(n + 1, vt(int)(n + 1, 0));

    int s, t;
    fr(i, 0, e)
    {
        cin >> s >> t;
        v[s][t] = v[t][s] = 1;
    }

    bfs(v, n, u);
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
