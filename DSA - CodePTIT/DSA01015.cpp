// * Code by Ducsjukapvippro
// * dont cry bae =))
// * neu ngay mai khong den thi sao?

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

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

void __vippro__()
{
    int n;
    cin >> n;

    queue<ll> q;
    q.push(9);

    ll m;
    while (1)
    {
        m = q.front();

        if (m % n == 0)
        {
            cout << m << '\n';
            return;
        }
        else
        {
            q.pop();
            m *= 10;
            q.push(m);
            q.push(m + 9);
        }
    }
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
