// * Code by Ducsjukapvippro
// * dont cry bae =))
// * neu ngay mai khong den thi sao?

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

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

int bs(vt(ll) & v, int &n, ll &k)
{
    if (v[0] > k)
        return -1;
    if (v[0] == k)
        return 1;
    int l, r;
    l = 0;
    r = n - 1;

    int ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (v[mid] <= k)
            ans = l = mid + 1;
        else
            r = mid - 1;
    }

    return ans;
}

void __vippro__()
{
    int n;
    ll k;

    cin >> n >> k;
    vt(ll) v(n);

    for (ll &i : v)
        cin >> i;

    cout << bs(v, n, k) << '\n';
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
