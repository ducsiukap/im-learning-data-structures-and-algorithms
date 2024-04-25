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
#define in(x, n) fe(i, 1, n) cin >> x[i]
#define out(x, n, sep) fr(i, 0, n) cout << x[i] << sep
#define reset(x, n, value) fe(i, 1, n) x[i] = value
int n, k, ans;
int a[100], x[100];

bool check()
{
    fe(i, 1, k) if (x[i] < x[i - 1]) return false;
    return true;
}

void Try(int i)
{
    fe(j, x[i - 1] + 1, n - k + i)
    {
        if (a[j] >= a[x[i - 1]])
        {
            if (i == k)
                ++ans;
            else
            {
                x[i] = j;
                Try(i + 1);
            }
        }
    }
}
void __vippro__()
{
    cin >> n >> k;
    in(a, n);

    a[0] = INT_MIN;
    ans = x[0] = 0;
    Try(1);
    cout << ans << '\n';
}

__ducsjukap__
{
    faster();
    // run() {
    __vippro__(); //}
    return 0;
}
// * Code by Ducsjukapvippro
