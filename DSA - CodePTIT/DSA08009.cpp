// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i <= b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

#define mp(a, b) make_pair(a, b)

void __vippro__()
{
    int n, k;
    queue<pair<int, int>> q;
    pair<int, int> p;

    cin >> n >> k;
    vector<bool> unused(2 * k, true);
    q.push(mp(n, 0));

    int res = 1e9;

    while (!q.empty())
    {
        p = q.front();
        q.pop();
        unused[p.first] = false;
        if (p.first >= k)
            res = min(res, p.second + p.first - k);
        else if (2 * p.first == k)
            res = max(res, p.second + 1);
        else
        {
            if (2 * p.first < 2 * k && unused[2 * p.first])
                q.push(mp(2 * p.first, p.second + 1));
            if (p.first && unused[p.first - 1])
                q.push(mp(p.first - 1, p.second + 1));
        }
    }
    cout << res << '\n';
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