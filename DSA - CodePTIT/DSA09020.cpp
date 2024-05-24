// * Code by Ducsjukapvippro
// * dont cry bae =))
// * neu ngay mai khong den thi sao?

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

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
#define out(x, n, sep) fe(i, 1, n) cout << x[i] << sep
#define reset(x, n, value) fr(i, 0, n) x[i] = value

void __vippro__()
{
    int n;
    cin >> n;
    cin.ignore();
    vt(vt(int)) v(n + 1, vt(int)(n + 1, 0));

    string s;
    int e;
    fe(i, 1, n)
    {
        getline(cin, s);
        stringstream ss(s);
        while (ss >> s)
        {
            e = stoi(s);
            v[e][i] = v[i][e] = 1;
        }
    }

    fe(i, 1, n)
    {
        fe(j, 1, n) cout << v[i][j] << ' ';
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
