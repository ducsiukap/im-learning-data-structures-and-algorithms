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
typedef unsigned long long ull;
typedef long double ld;

void __vippro__()
{
    int n;
    ull res;
    queue<ull> q;
    cin >> n;
    q.push(1);
    while (1)
    {
        res = q.front();
        q.pop();
        if (res % n)
        {
            res *= 10;
            q.push(res);
            q.push(res + 1);
        }
        else
        {
            cout << res << '\n';
            return;
        }
    }
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