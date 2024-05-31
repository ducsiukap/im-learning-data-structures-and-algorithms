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
#define in(x, n) fr(itr, 0, n) cin >> x[itr]
#define out(x, n, sep) fr(itr, 0, n) cout << x[itr] << sep
#define reset(x, n, value) fr(itr, 0, n) x[itr] = value

struct work
{
    int id, deadline, profit;
};

bool cmp(work &a, work &b) { return a.profit > b.profit; }

void __vippro__()
{
    int n;
    cin >> n;

    vt(work) works(n);

    for (work &i : works)
        cin >> i.id >> i.deadline >> i.profit;

    sort(all(works), cmp);

    vt(bool) slot(1000, false);
    int w, p;
    w = p = 0;

    for (work &W : works)
    {
        de(i, W.deadline - 1, 0)
        {
            if (slot[i] == false)
            {
                ++w;
                p += W.profit;

                slot[i] = true;
                break;
            }
        }
    }

    cout << w << ' ' << p << '\n';
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
