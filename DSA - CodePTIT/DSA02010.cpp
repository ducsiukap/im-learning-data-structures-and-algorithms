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

int A[25], n, k;
v(int) x;
v(v(int)) res;

void Try(int i)
{
    fr(j, i, n)
    {
        x.push_back(A[j]);
        k -= A[j];

        if (k == 0)
            res.push_back(x);
        else if (k - A[j] >= 0)
            Try(j);

        k += A[j];
        x.pop_back();
    }
}

void __vippro__()
{
    cin >> n >> k;
    in(A, n);
    sort(A, A + n);

    x.clear();
    res.clear();
    Try(0);

    if (sz(res) == 0)
        cout << "-1\n";
    else
    {
        for (v(int) v : res)
        {
            cout << '[';
            fr(i, 0, sz(v) - 1) cout << v[i] << ' ';
            cout << v[sz(v) - 1] << ']';
        }
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
