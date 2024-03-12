// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <string>
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
    string s, res, tmp;
    int cnt;
    stack<int> cs;
    stack<string> ss;
    cin >> s;
    cnt = 0;
    res = "";
    for (char &c : s)
    {
        if (isdigit(c))
            cnt = cnt * 10 + c - '0';
        else if (isalpha(c))
            res += c;
        else if (c == '[')
        {
            cs.push(cnt);
            ss.push(res);
            cnt = 0;
            res = "";
        }
        else
        {
            tmp = "";
            cnt = cs.top();
            while (cnt--)
                tmp += res;
            res = ss.top() + tmp;
            cs.pop();
            ss.pop();
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