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

void print_ops(queue<int> &q, int &n)
{
    if (q.empty())
        cout << "-1\n";
    else if (n == 5)
        cout << q.front() << '\n';
    else
        cout << q.back() << '\n';
}
void __vippro__()
{
    int qs, ops, x;
    queue<int> q;
    cin >> qs;
    do
    {
        cin >> ops;
        switch (ops)
        {
        case 1:
            cout << q.size() << '\n';
            break;
        case 2:
            cout << (q.empty() ? "YES\n" : "NO\n");
            break;
        case 3:
            cin >> x;
            q.push(x);
            break;
        case 4:
            if (!q.empty())
                q.pop();
            break;
        default:
            print_ops(q, ops);
            break;
        }
    } while (--qs);
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