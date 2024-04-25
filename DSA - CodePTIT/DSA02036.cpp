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

int a[20], n;
int x[20];

bool genNext()
{
    int i = n - 1;
    while (i >= 0 && x[i])
    {
        x[i] = 0;
        --i;
    }
    if (i >= 0)
    {
        x[i] = 1;
        return 1;
    }
    return 0;
}
void __vippro__()
{
    cin >> n;
    in(a, n);
    sort(a, a + n, greater<int>());
    reset(x, n, 0);

    v(int) v;
    v(v(int)) res;
    int sum;

    while (genNext())
    {
        v.clear();
        sum = 0;
        fr(i, 0, n)
        {
            if (x[i])
            {
                sum += a[i];
                v.push_back(a[i]);
            }
        }
        if (sum & 1)
            res.push_back(v);
    }

    fr(i, 0, sz(res))
    {
        out(res[i], sz(res[i]), ' ');
        cout << '\n';
    }
}

__ducsjukap__
{
    // faster();
    run()
        __vippro__();
    system("pause");
    return 0;
}
// * Code by Ducsjukapvippro
