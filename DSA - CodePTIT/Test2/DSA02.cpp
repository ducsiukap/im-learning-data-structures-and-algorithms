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

int MOD = 1e9 + 7;
void __vippro__()
{
    int n;
    cin >> n;
    v(v(ll)) dp(n + 1, v(ll)(10, 1));

    fe(i, 0, n) dp[i][0] = 1;

    // dp[i][j] là số các số thỏa mãn có độ dài là i, không giảm và kết thúc = j
    fe(i, 1, n)
    {
        fe(j, 1, 9)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % (MOD);
    }
    fe(i, 1, n) cout << dp[i][9] << '\t';
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
