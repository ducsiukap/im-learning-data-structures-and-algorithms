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
#define reset(x, n, value) fe(i, 1, n) x[i] = value

int n, k;
bool used[50];
int x[50];
int ans;

void check()
{
    int i = k;
    while (i && x[i] == n - k + i)
    {
        used[x[i]] = true;
        --i;
    }
    if (i)
    {
        ans = 0;
        ++x[i];
        fe(j, i + 1, k)
            x[j] = x[j - 1] + 1;
        fe(j, i, k) if (!used[x[j]])++ ans;
    }
    else
        ans = k;
}

void __vippro__()
{
    cin >> n >> k;
    in(x, k);
    reset(used, n, false);
    check();
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
