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
#define in(x, n) fr(i, 0, n) cin >> x[i]
#define out(x, n, sep) fr(i, 0, n) cout << x[i] << sep
#define reset(x, n, value) fr(i, 0, n) x[i] = value

void __vippro__()
{
    int n, k, s;
    int ans, sum;
    while (1)
    {
        cin >> n >> k >> s;
        if (n == 0 && k == 0 && s == 0)
            break;
        if (k > n || k * (k + 1) / 2 + (n - k) * k < s)
        {
            cout << '0' << '\n';
            continue;
        }

        ans = 0;
        string ss = string(k, '0') + string(n - k, '1');
        do
        {
            sum = 0;
            fr(i, 0, n) if (ss[i] == '0') sum += i + 1;
            ans += (sum == s);
        } while (next_permutation(all(ss)));
        cout << ans << '\n';
    }
}

__ducsjukap__
{
    // faster();
    // run()
    __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
