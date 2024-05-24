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

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
int n, m;

void dfs(vt(vt(char)) & v, int x, int y)
{
    if (x < 0 || x >= m || y < 0 || y >= n || v[y][x] != '1')
        return;

    v[y][x] = '-';

    fr(i, 0, 8)
        dfs(v, x + dx[i], y + dy[i]);
}

int count_island(vt(vt(char)) & v)
{
    int cnt = 0;
    fr(i, 0, n) fr(j, 0, m) if (v[i][j] == '1')
    {
        ++cnt;
        dfs(v, j, i);
    }

    return cnt;
}

void __vippro__()
{
    cin >> n >> m;

    vt(vt(char)) v(n, vt(char)(m));

    fr(i, 0, n) fr(j, 0, m) cin >> v[i][j];

    cout << count_island(v) << '\n';
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
