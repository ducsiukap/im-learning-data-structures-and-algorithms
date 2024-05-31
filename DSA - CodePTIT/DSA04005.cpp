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

vt(int) f(93);
char solve(int n, ll k)
{
    if (n < 3)
        return (n == 1 ? 'A' : 'B');

    if (k <= f[n - 2])
        return solve(n - 2, k);
    else
        return solve(n - 1, k - f[n - 2]);
}
void __vippro__()
{
    int n;
    ll k;
    cin >> n >> k;

    cout << solve(n, k) << '\n';
}

__ducsjukap__
{
    faster();
    f[0] = 0;
    f[1] = 1;
    f[2] = 1;
    fr(i, 3, 93)
        f[i] = f[i - 1] + f[i - 2];
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
