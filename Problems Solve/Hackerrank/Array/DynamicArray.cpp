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
#define fd(i, a, b) for (i = a; i < b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

void __vippro__()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> v(n);
    int lastAnswer, opt, x, y, idx;
    lastAnswer = 0;
    do
    {
        cin >> opt >> x >> y;
        if (opt == 1)
        {
            idx = (x ^ lastAnswer) % n;
            v[idx].push_back(y);
        }
        else
        {
            idx = (x ^ lastAnswer) % n;
            lastAnswer = v[idx][y % v[idx].size()];
            cout << lastAnswer << '\n';
        }
    } while (--q);
}

__ducsjukap__()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    // cin >> T;
    dr(T, 1, 0)
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
