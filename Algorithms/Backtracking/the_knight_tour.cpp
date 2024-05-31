// * Code by Ducsjukapvippro
// * dont cry bae =))
// * neu ngay mai khong den thi sao?

// The Knight's Tour problem: https://www.geeksforgeeks.org/the-knights-tour-problem/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

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

int x[] = {2, 1, -1, -2, -2, -1, 1, 2};
int y[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int n;

bool Try(vt(vt(int)) & v, int r, int c, int step)
{
    if (r < 0 || r >= n || c < 0 || c >= n || v[r][c])
        return false;

    v[r][c] = step;

    if (step == n * n)
        return true;

    fr(i, 0, 8) if (Try(v, r + y[i], c + x[i], step + 1)) return true;

    v[r][c] = 0;
    return false;
}

void __vippro__()
{
    cin >> n;

    vt(vt(int)) v(n, vt(int)(n, 0));

    if (Try(v, 0, 0, 1))
        fr(i, 0, n)
        {
            fr(j, 0, n) cout << setw(2) << v[i][j] << ' ';
            cout << '\n';
        }
    else
        cout << "no answer for this problem!\n";
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
