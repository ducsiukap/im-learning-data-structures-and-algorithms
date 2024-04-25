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

bool col[100], cross1[100], cross2[100];
int a[100][100], bestValue;

void Try(int i, int val)
{
    if (i == 9)
    {
        bestValue = max(bestValue, val);
        return;
    }
    fe(j, 1, 8)
    {
        if (col[j] && cross1[i - j + 8] && cross2[j + i])
        {
            col[j] = cross1[i - j + 8] = cross2[i + j] = false;
            Try(i + 1, val + a[i][j]);
            col[j] = cross1[i - j + 8] = cross2[i + j] = true;
        }
    }
}

void __vippro__()
{
    fe(j, 1, 8) in(a[j], 8);

    reset(col, 100, true);
    reset(cross1, 100, true);
    reset(cross2, 100, true);
    bestValue = 0;

    Try(1, 0);
    cout << bestValue << '\n';
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
