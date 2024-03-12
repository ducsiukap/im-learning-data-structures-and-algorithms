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

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

void solve()
{
    int n;
    vector<pair<int, int>> v;
    cin >> n;
    v.resize(n);
    int i, last_time, res;
    fr(i, 0, n) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), cmp);
    res = 1;
    last_time = v[0].second;
    fr(i, 1, n) if (v[i].first >= last_time)
    {
        ++res;
        last_time = v[i].second;
    }
    cout << res << '\n';
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