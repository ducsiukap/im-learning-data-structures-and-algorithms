// * Code by Ducsjukapvippro
// * dont cry bae =))
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define __ducsjukap__() main()
#define fr(i, a, b) for (i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i < b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

void solve()
{
    int n, lmax, rmax;
    vector<int> v;
    cin >> n;
    v.resize(n);
    fr(lmax, 0, n) cin >> v[lmax];
    sort(v.begin(), v.end());
    lmax = v[0] * v[1];
    lmax = max(lmax, lmax * v[n - 1]);
    rmax = v[n - 1] * v[n - 2];
    rmax = max(rmax, rmax * v[n - 3]);
    cout << max(lmax, rmax) << '\n';
}

int __ducsjukap__()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    // cin >> T;
    dr(T, 1, 0)
        solve();
    return 0;
}
// * Code by Ducsjukapvippro