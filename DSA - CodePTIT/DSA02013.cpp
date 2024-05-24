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

vt(int) P;
int n;

void inittt()
{
    vt(bool) v(201, true);

    fe(i, 2, 14)
    {
        if (v[j])
            for (int j = i * i; j <= 200; j += i)
                v[j] = 0;
    }

    fr(i, 2, 200) if (v[i]) P.push_back(i);
    n = sz(P);
}

vt(vt(int)) res;

void Try(vt(int) & ans, int i, int &en, int &n1, int &s, int sum)
{
    fr(j, ans[i - 1] + 1, en - i + 1)
    {
        ans[i] = j;
        sum += P[j];

        if (i == n1)
        {
            if (sum == s)
                res.push_back(ans);
        }
        else if (i < n1 && sum < s)
            Try(ans, i + 1, en, n1, s, sum);
        sum -= P[j];
    }
}

void __vippro__()
{
    int n1, p, s;
    cin >> n1 >> p >> s;

    if (p > s)
    {
        cout << 0 << '\n';
        return;
    }

    int en = 0;
    while (en < n && v[en] < p)
        ++en;

    vt(int) ans;
    ans.push_back(en - 1);

    while (en < n && v[en] <= s)
        ++en;

    --en;
    Try(ans, 1, en, n1, s, 0);
    cout << sz(res) << '\n';
}

__ducsjukap__
{
    faster();
    inittt();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
