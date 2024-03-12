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

int findMax(vector<int> &v, int beg, int end)
{
    int m = v[beg], i;
    fr(i, beg + 1, end) m = max(m, v[i]);
    return m;
}

void __vippro__()
{
    int n, k, maxx, i;
    cin >> n >> k;
    vector<int> v(n);
    fr(i, 0, n) cin >> v[i];

    maxx = findMax(v, 0, k);
    cout << maxx << ' ';
    fr(i, k, n)
    {
        if (v[i] < maxx && maxx == v[i - k])
            maxx = findMax(v, i - k + 1, i + 1);
        else
            maxx = max(maxx, v[i]);
        cout << maxx << ' ';
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