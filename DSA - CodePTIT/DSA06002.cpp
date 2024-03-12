// * Code by Ducsjukapvippro
// * dont cry bae =))
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i < b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

int x;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    int i = abs(x - a.first);
    int j = abs(x - b.first);
    if (i == j)
        return a.second < b.second;
    return i < j;
}
void __vippro__()
{
    int n, i;
    vector<pair<int, int>> v;
    cin >> n >> x;
    v.resize(n);
    fr(i, 0, n)
    {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end(), cmp);
    fr(i, 0, n) cout << v[i].first << ' ';
    cout << '\n';
    v.clear();
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