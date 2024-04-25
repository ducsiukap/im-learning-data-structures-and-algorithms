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
#define in(x, n) fr(i, 0, n) cin >> x[i]
#define out(x, n, sep) fr(i, 0, n) cout << x[i] << sep
#define reset(x, n, value) fr(i, 0, n) x[i] = value

struct item
{
    int cost, value;
    float hs;
};

bool cmp(item a, item b)
{
    return a.hs >= b.hs;
}

int Maxcost = 1e9;

int x[100005], n, maxVal;
v(item) a(n);

void Try(int i, int val)
{
    fr(j, 0, 2)
    {
        x[i] = j;
        val += j * a[i].value;
        Maxcost -= j * a[i].cost;
        if (Maxcost >= 0)
        {
            if (i == n - 1)
                maxVal = max(maxVal, val);
            else
                Try(i + 1, val);
        }
        val -= j * a[i].value;
        Maxcost += j * a[i].cost;
    }
}

void __vippro__()
{
    cin >> n;
    a.resize(n);
    fr(i, 0, n)
    {
        cin >> a[i].cost >> a[i].value;
        a[i].hs = 1.0 * a[i].value / a[i].cost;
    }
    sort(all(a), cmp);

    Maxcost = 0;
    Try(1, 0);
    cout << maxVal << '\n';
}

__ducsjukap__
{
    // faster();
    // run()
    __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
