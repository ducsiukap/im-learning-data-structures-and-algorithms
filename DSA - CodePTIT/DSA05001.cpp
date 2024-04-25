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
#define v(x) vector<x>
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

int lcs(string &x, string &y, int m, int n, v(v(int)) & dp)
{
    if (m == 0 || n == 0)
        return 0;
    if (x[m - 1] == y[n - 1])
        return dp[m][n] = 1 + lcs(x, y, m - 1, n - 1, dp);
    if (dp[m][n] != -1)
        return dp[m][n];
    return dp[m][n] = max(lcs(x, y, m - 1, n, dp), lcs(x, y, m, n - 1, dp));
}

void __vippro__()
{
    string x, y;
    cin >> x >> y;
    int m, n;
    m = sz(x);
    n = sz(y);
    v(v(int)) dp(m + 1, v(int)(n + 1, -1));
    cout << lcs(x, y, m, n, dp) << '\n';
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
