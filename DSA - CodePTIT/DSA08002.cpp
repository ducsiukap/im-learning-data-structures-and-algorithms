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
    int qs, x;
    string ops;
    queue<int> q;
    cin >> qs;
    do
    {
        cin >> ops;
        if (ops[1] == 'U')
        {
            cin >> x;
            q.push(x);
        }
        else if (ops[1] == 'O')
        {
            if (!q.empty())
                q.pop();
        }
        else
        {
            if (q.empty())
                cout << "NONE\n";
            else
                cout << q.front() << '\n';
        }
    } while (--qs);
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