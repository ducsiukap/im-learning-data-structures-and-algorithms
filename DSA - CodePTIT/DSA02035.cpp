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

int to_int(string &s, vt(int) & x, int &k)
{
    int num = 0;
    fr(i, 0, k)
        num = num * 10 + s[x[i]] - '0';
    return num;
}

int get_distance(vt(string) & v, vt(int) & x, int &n, int &k)
{
    int m = to_int(v[0], x, k);
    int M = to_int(v[0], x, k);

    fr(i, 1, n)
    {
        int num = to_int(v[i], x, k);

        if (num < m)
            m = num;
        if (num > M)
            M = num;
    }

    return (M - m);
}

void __vippro__()
{
    int n, k;
    cin >> n >> k;
    vt(string) v(n);

    for (string &s : v)
        cin >> s;

    vt(int) x(k);
    fr(i, 0, k) x[i] = i;

    int ans = get_distance(v, x, n, k);

    while (next_permutation(all(x)))
        ans = min(ans, get_distance(v, x, n, k));

    cout << ans << '\n';
}

__ducsjukap__
{
    faster();
    // run()
    __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
