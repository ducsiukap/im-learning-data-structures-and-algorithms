// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
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
    string s;
    stack<int> res;
    int a, b, i;
    cin >> s;
    dd(i, s.size() - 1, 0)
    {
        if (isdigit(s[i]))
            res.push(s[i] - '0');
        else
        {
            a = res.top();
            res.pop();
            b = res.top();
            res.pop();
            if (s[i] == '+')
                res.push(a + b);
            else if (s[i] == '-')
                res.push(a - b);
            else if (s[i] == '*')
                res.push(a * b);
            else
                res.push(a / b);
        }
    }
    cout << res.top() << '\n';
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