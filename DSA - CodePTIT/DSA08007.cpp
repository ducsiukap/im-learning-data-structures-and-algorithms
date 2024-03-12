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
    ull n, tmp;
    int res;
    queue<int> q;
    cin >> n;
    q.push(1);
    res = 0;
    while (!q.empty() && q.front() <= n)
    {
        tmp = q.front();
        q.pop();
        ++res;
        tmp *= 10;
        q.push(tmp);
        q.push(tmp + 1);
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