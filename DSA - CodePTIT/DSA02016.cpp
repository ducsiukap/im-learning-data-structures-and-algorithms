// * Code by Ducsjukapvippro
// * dont cry bae =))
// * neu ngay mai khong den thi sao?

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

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

bool checkPoint(vt(int) & row, int &i)
{
    fr(j, 0, i)
    {
        if ((row[j] == row[i]) || (abs(i - j) == abs(row[i] - row[j])))
            return false;
    }

    return true;
}

int ans;

void Try(vt(int) & row, int &n, int i)
{
    if (i == n)
    {
        ++ans;
        return;
    }

    fr(j, 0, n)
    {
        row.push_back(j);
        if (checkPoint(row, i))
            Try(row, n, i + 1);
        row.pop_back();
    }
}

void __vippro__()
{
    int n;
    cin >> n;

    vt(int) row;
    ans = 0;

    Try(row, n, 0);
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
