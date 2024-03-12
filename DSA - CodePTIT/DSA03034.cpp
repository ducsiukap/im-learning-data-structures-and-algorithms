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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> va(n), vb(m), vc(k), res;
    int i, j, l;
    fr(i, 0, n) cin >> va[i];
    fr(j, 0, m) cin >> vb[j];
    fr(l, 0, k) cin >> vc[l];
    i = j = l = 0;
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    sort(vc.begin(), vc.end());
    while (i < n && j < m && l < k)
    {
        if (va[i] == vb[j] && va[i] == vc[l])
        {
            res.push_back(va[i]);
            ++i;
            ++j;
            ++l;
        }
        else if (va[i] < vb[j])
            ++i;
        else if (vb[j] < vc[l])
            ++j;
        else
            ++l;
    }
    if (res.empty())
        cout << "NO";
    else
        for (int &x : res)
            cout << x << ' ';
    cout << '\n';
    va.clear();
    vb.clear();
    vc.clear();
    res.clear();
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