// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i <= b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

void __vippro__()
{
    int n, i, x;
    vector<int> v(100001, 0);
    cin >> n;
    fr(i, 0, n)
    {
        cin >> x;
        ++v[x];
    }
    vector<pair<int, int>> res;
    fr(i, 0, 100001) if (v[i]) res.push_back(make_pair(i, v[i]));
    sort(res.begin(), res.end(), cmp);
    for (pair<int, int> &p : res)
        while (p.second)
        {
            cout << p.first << ' ';
            --p.second;
        }
    cout << '\n';
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
