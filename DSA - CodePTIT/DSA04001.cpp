// * Code by Ducsjukapvippro
// * dont cry bae =))
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i < b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

int mod = 1e9 + 7;

void solve()
{
    ll n;
    int k;
    cin >> n >> k;
    ll res = 1;
    while (k)
    {
        if (k & 1)
            res = res * n % mod;
        k /= 2;
        n = n * n % mod;
    }
    cout << res << '\n';
}

__ducsjukap__()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    dr(T, T, 0)
        solve();
    return 0;
}
// * Code by Ducsjukapvippro