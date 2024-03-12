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

ll rev(ll n)
{
    ll res = 0;
    while (n > 0)
    {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

ll p(ll a, ll b)
{
    if (!b)
        return 1;
    ll x = p(a, b / 2) % mod;
    x = x * x % mod;
    if (b & 1)
        return a * x % mod;
    else
        return x;
}

void __vippro__()
{
    ll n, k;
    cin >> n;
    k = rev(n);
    cout << p(n, k) << '\n';
}

__ducsjukap__()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    int T;
    cin >> T;
    dr(T, T, 0)
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro