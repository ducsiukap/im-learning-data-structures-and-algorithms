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
#define in(x, n) fr(i, 0, n) cin >> x[i]
#define out(x, n, sep) fr(i, 0, n) cout << x[i] << sep
#define reset(x, n, value) fr(i, 0, n) x[i] = value

int findRoot(int in[], int &x, int &n) { fr(i, 0, n) if (in[i] == x) return i; }

void postOrd(int in[], int pre[], int n)
{
    int posRoot = findRoot(in, pre[0], n);

    if (posRoot)
        postOrd(in, pre + 1, posRoot);
    if (posRoot != n - 1)
        postOrd(in + posRoot + 1, pre + posRoot + 1, n - posRoot - 1);

    cout << pre[0] << ' ';
}

void __vippro__()
{
    int in[1005], pre[1005];
    int n;
    cin >> n;
    fr(i, 0, n) cin >> in[i];
    fr(i, 0, n) cin >> pre[i];

    postOrd(in, pre, n);
    cout << '\n';
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
