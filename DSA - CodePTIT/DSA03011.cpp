// 2 4 1 2 10 2 3
//  1 2 2 2 3 4 10
/*
cp     dai       arr
3       3   2 2 3 3 4 10
7       4   3 3 4 4 10
13      6   4 4 6 10
21      8   6 8 10
35      14  10 14
59      24  24
*/

// * Code by Ducsjukapvippro
// * dont cry bae =))
// * neu ngay mai khong den thi sao?

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
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
int m = 1e9 + 7;

bool cmp(ll &a, ll &b) { return a < b; }
int calc(vt(int) & v, int &n)
{
    priority_queue<ll, vt(ll), greater<ll>> pq(all(v));

    ll res = 0, a;

    while (sz(pq) > 1)
    {
        a = pq.top();
        pq.pop();
        a += pq.top();
        pq.pop();

        a %= m;
        pq.push(a);

        res += a;
        res %= m;
    }

    return res;
}

void __vippro__()
{
    int n;
    cin >> n;
    vt(int) v(n);
    in(v, n);

    cout << calc(v, n) << '\n';
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
