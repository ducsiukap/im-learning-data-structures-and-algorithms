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
#define out(x, n) fe(i, 1, n) cout << x[i]
#define reset(x, n, value) fe(i, 1, n) x[i] = value
int n, k, ans;
vector<char> x(100);
vector<vector<char>> v;
bool check()
{
    int maxX = 0, cnt = 0;
    fe(i, 1, n)
    {
        if (x[i] == 'B')
        {
            maxX = max(cnt, maxX);
            cnt = 0;
        }
        else
            ++cnt;
    }
    maxX = max(cnt, maxX);
    return (maxX == k);
}

bool genNext()
{
    if (check())
        v.push_back(x);
    int i = n;
    while (i && x[i] == 'B')
    {
        x[i] = 'A';
        --i;
    }

    if (i)
    {
        x[i] = 'B';
        return true;
    }
    return false;
}
void __vippro__()
{
    cin >> n >> k;
    reset(x, n, 'A');

    while (genNext())
        ;

    cout << v.size() << '\n';
    for (vector<char> a : v)
    {
        out(a, n);
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
