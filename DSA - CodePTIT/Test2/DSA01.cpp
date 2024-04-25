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

int n, a, b;
bool x[10];

bool getsum(v(int) & v)
{
    int sum = 0;
    fr(i, 0, n) if (x[i])
        sum += v[i];
    return (sum >= a && sum <= b);
}
bool genNext()
{
    int i = n - 1;
    while (i >= 0 && x[i])
    {
        x[i] = false;
        --i;
    }
    if (i == -1)
        return false;
    x[i] = 1;
    return true;
}
void __vippro__()
{
    cin >> n >> a >> b;
    v(int) vt(n);
    fr(i, 0, n) cin >> vt[i];

    int ans = 0;
    reset(x, 10, 0);
    do
    {
        ans += getsum(vt);
    } while (genNext());
    cout << ans << '\n';
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
