// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i <= b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

void __vippro__()
{
    int a, b, x, y, i;
    cin >> x >> y;
    vector<set<int>> v(x + 1);
    fr(i, 0, y)
    {
        cin >> a >> b;
        v[a].insert(b);
        v[b].insert(a);
    }

    fd(i, 0, x)
    {
        if (!v[i].empty())
        {
            cout << i << ':';
            for (int e : v[i])
                cout << ' ' << e;
            cout << '\n';
        }
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