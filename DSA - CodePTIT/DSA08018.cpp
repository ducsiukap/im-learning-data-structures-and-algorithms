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

void __vippro__()
{
    int n;
    string res;
    queue<string> q, result;
    cin >> n;
    q.push("");

    while (!q.empty())
    {
        res = q.front();
        q.pop();
        result.push(res);
        if (res.size() < n)
        {
            q.push(res + '6');
            q.push(res + '8');
        }
    }
    result.pop(); // delete ""
    cout << result.size() << '\n';
    while (!result.empty())
    {
        cout << result.front() << ' ';
        result.pop();
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