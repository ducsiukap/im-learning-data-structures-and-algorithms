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
    int n, m, i, j;
    cin >> n >> m;
    vector<int> va(n), vb(m), It;
    fr(i, 0, n) cin >> va[i];
    fr(i, 0, m) cin >> vb[i];
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    i = j = 0;
    while (i < n && j < m)
    {
        if (va[i] == vb[j])
        {
            cout << va[i] << ' ';
            It.push_back(va[i]);
            ++i;
            ++j;
        }
        else if (va[i] < vb[j])
        {
            cout << va[i] << ' ';
            ++i;
        }
        else
        {
            cout << vb[j] << ' ';
            ++j;
        }
    }
    while (i < n)
    {
        cout << va[i] << ' ';
        ++i;
    }
    while (j < m)
    {
        cout << vb[j] << ' ';
        ++j;
    }
    cout << '\n';
    for (int &x : It)
        cout << x << ' ';
    cout << '\n';
}

__ducsjukap__()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    int T;
    cin >> T;
    dr(T, T, 0)
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
