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
#define in(x, n) fr(itr, 0, n) cin >> x[itr]
#define out(x, n, sep) fr(itr, 0, n) cout << x[itr] << sep
#define reset(x, n, value) fr(itr, 0, n) x[itr] = value

void solve(int &n)
{
    if (n % 7 == 0)
    {
        while (n)
        {
            cout << 7;
            n -= 7;
        }
        cout << '\n';
        return;
    }

    if (n % 4 == 0)
    {
        while (n)
        {
            cout << 4;
            n -= 4;
        }
        cout << '\n';
        return;
    }

    int x = n % 7;
    while ((x % 4) && (x <= n))
        x += 7;
    if (x > n)
        cout << -1 << '\n';
    else
    {
        n -= x;
        while (x)
        {
            cout << 4;
            x -= 4;
        }
        while (n)
        {
            cout << 7;
            n -= 7;
        }
        cout << '\n';
    }
}

void __vippro__()
{
    int s;
    cin >> s;

    solve(s);
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
