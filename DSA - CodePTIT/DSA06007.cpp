// * Code by Ducsjukapvippro
// * dont cry bae =))
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i < b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

void __vippro__()
{
    int beg, fin;
    cin >> fin;
    vector<int> v(fin);
    fr(beg, 0, fin) cin >> v[beg];
    vector<int> vsort = v;
    sort(vsort.begin(), vsort.end());
    fr(beg, 0, fin) if (v[beg] != vsort[beg]) break;
    dd(fin, fin - 1, 0) if (v[fin] != vsort[fin]) break;
    cout << beg + 1 << ' ' << fin + 1 << '\n';
}

__ducsjukap__()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    dr(T, T, 0)
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro