// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i <= b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

void __vippro__()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);

    int i;
    fr(i, 0, n) cin >> v[i];
    sort(v.begin(), v.end());
    ll ans = 0;
    fr(i, 0, n)
    {
        auto it = lower_bound(v.begin() + i + 1, v.end(), k + v[i]) - 1;
        ans += it - v.begin() - i;
    }
    cout << ans << '\n';
}

__ducsjukap__()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    dr(T, T, 0)
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro