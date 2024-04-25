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
#define out(x, n, sep) fe(i, 1, n) cout << x[i] << sep
#define reset(x, n, val) fe(i, 1, n) x[i] = val
int n, w;
int a[100], c[100];
bool x[100], xopt[100];
int fopt;

bool genNext()
{
    int i = n;
    while (i && x[i])
    {
        x[i] = false;
        --i;
    }

    if (i)
    {
        x[i] = true;
        int maxVal = 0, maxCost = 0;
        fe(j, 1, i) if (x[j])
        {
            maxVal += a[j];
            maxCost += c[j];
        }
        if (maxVal > fopt && maxCost <= w)
        {
            fopt = maxVal;
            fe(j, 1, n)
                xopt[j] = x[j];
        }
        return true;
    }

    return false;
}

void __vippro__()
{
    cin >> n >> w;
    in(a, n);
    in(c, n);
    reset(x, n, false);
    reset(xopt, n, false);
    fopt = 0;

    while (genNext())
        ;

    cout << fopt << '\n';
    out(xopt, n, ' ');
    cout << '\n';
}

__ducsjukap__
{
    faster();
    // run()
    __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
