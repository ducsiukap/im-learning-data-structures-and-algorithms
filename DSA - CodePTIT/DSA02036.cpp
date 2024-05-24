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

bool genNext(vt(int) & x, int n)
{
    int i = 0;
    while ((i < n) && (x[i]))
    {
        x[i] = 0;
        ++i;
    }

    if (i == n)
        return false;

    x[i] = 1;
    return true;
}

void __vippro__()
{
    int n;
    cin >> n;

    vt(int) v(n);

    for (int &i : v)
        cin >> i;

    sort(all(v));
    vt(int) x(n, 0);

    vt(vt(int)) res;

    while (genNext(x, n))
    {
        int sum = 0;
        fr(i, 0, n)
            sum += x[i] * v[i];

        if (sum & 1)
        {
            vt(int) tmp;
            de(i, n - 1, 0) if (x[i]) tmp.pb(v[i]);

            res.pb(tmp);
        }
    }

    for (vt(int) & a : res)
    {
        for (int &b : a)
            cout << b << ' ';
        cout << '\n';
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
