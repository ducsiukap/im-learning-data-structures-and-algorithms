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

void rebuild_string(string &s, int &k, int i, string &res)
{
    if (k == 0)
        return;

    int j = i;

    fr(x, i + 1, sz(s)) if (s[x] > s[j]) j = x;

    if (s[j] != s[i])
        --k;

    de(x, sz(s) - 1, i)
    {
        if (s[x] == s[j])
        {
            swap(s[x], s[i]);
            if (s > res)
                res = s;
            rebuild_string(s, k, i + 1, res);
            swap(s[x], s[i]);
        }
    }
}
void __vippro__()
{
    string s;
    int k;
    cin >> k >> s;
    string res = s;
    rebuild_string(s, k, 0, res);
    cout << res << '\n';
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro