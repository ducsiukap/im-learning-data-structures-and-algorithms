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
    int n, s, m;
    cin >> n >> s >> m;
    if (n < m || 6 * (n - m) < m)
        cout << "-1\n";
    else
    {
        s *= m;
        m = s / n;
        if (m * n != s)
            ++m;
        cout << m << '\n';
    }
}

int __ducsjukap__()
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