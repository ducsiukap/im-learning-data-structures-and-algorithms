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

int n, k;
int a[100];
v(int) x;
v(v(int)) v;

void Try(int i, int sum)
{
    fr(j, i, n)
    {
        x.push_back(a[j]);
        sum += a[j];

        if (sum == k)
            v.push_back(x);
        else if (sum + a[j] <= k)
            Try(j, sum);

        x.pop_back();
        sum -= a[j];
    }
}
void __vippro__()
{
    cin >> n >> k;
    in(a, n);

    x.clear();
    v.clear();
    Try(0, 0);

    int ans = sz(v);
    if (ans)
    {
        cout << ans << ' ';
        fr(i, 0, ans)
        {
            cout << '{';
            fr(j, 0, sz(v[i]) - 1) cout << v[i][j] << ' ';
            cout << v[i][sz(v[i]) - 1] << "} ";
        }
    }
    else
        cout << -1;
    cout << '\n';
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
