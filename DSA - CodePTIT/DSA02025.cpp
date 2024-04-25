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
#define reset(x, n, value) fr(i, 0, n) x[i] = value

int n, ans;
string vs[15];
bool mark[26];

int check(string &a, string &b)
{
    reset(mark, 26, false);
    int cnt = 0;
    fr(i, 0, sz(a)) mark[a[i] - 'A'] = true;
    fr(i, 0, sz(b)) cnt += mark[b[i] - 'A'];
    return cnt;
}

void __vippro__()
{
    cin >> n;
    in(vs, n);

    v(int) x(n);
    fr(i, 0, n) x[i] = i + 1;
    ans = 260;

    int cnt;
    do
    {
        cnt = 0;
        fr(i, 0, n - 1) cnt += check(vs[x[i]], vs[x[i + 1]]);

        ans = min(cnt, ans);
    } while (next_permutation(all(x)));
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
