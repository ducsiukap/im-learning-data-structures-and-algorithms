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

int A[15][15];

void __vippro__()
{
    int n, k;
    cin >> n >> k;
    fe(j, 1, n) in(A[j], n);

    int sum;
    v(int) x(n);
    fr(i, 0, n) x[i] = i + 1;

    v(v(int)) res;
    do
    {
        sum = A[1][x[0]];
        fr(i, 1, n) sum += A[i + 1][x[i]];
        if (sum == k)
            res.push_back(x);
    } while (next_permutation(all(x)));

    cout << sz(res) << '\n';
    for (v(int) v : res)
    {
        out(v, sz(v), ' ');
        cout << '\n';
    }
}

__ducsjukap__
{
    faster();
    // run()
    __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
