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

bool check_coloring(vt(int) & vertex_color, vt(int) & ke, int &color)
{
    for (int &t : ke)
        if (vertex_color[t] == color)
            return false;

    return true;
}

bool Try(vt(int) & vertex_color, vt(vt(int)) & ke, int &n, int &m, int i)
{
    fe(j, 1, m)
    {
        if (check_coloring(vertex_color, ke[i], j))
        {
            vertex_color[i] = j;

            if (i == n)
                return true;
            else if (Try(vertex_color, ke, n, m, i + 1) == true)
                return true;

            vertex_color[i] = 0;
        }
    }

    return false;
}

void __vippro__()
{
    int n, ne, m;
    cin >> n >> ne >> m;

    vt(vt(int)) ke(n + 1);

    fr(i, 0, ne)
    {
        int u, v;
        cin >> u >> v;
        ke[u].pb(v);
        ke[v].pb(u);
    }

    vt(int) vertex_color(n + 1, 0);
    if (Try(vertex_color, ke, n, m, 1))
        cout << "YES";
    else
        cout << "NO";

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
