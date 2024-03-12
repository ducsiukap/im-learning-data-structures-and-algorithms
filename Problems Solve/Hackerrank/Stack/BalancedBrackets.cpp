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
bool isMatched(char &c, char &d)
{
    if (c == '{')
        return d == '}';
    else if (c == '[')
        return d == ']';
    else if (c == '(')
        return d == ')';
    else
        return false;
}
string isBalanced(string &str)
{
    stack<char> s;
    for (char &c : str)
    {
        if (c == '[' || c == '(' || c == '{')
            s.push(c);
        else
        {
            if (s.empty())
                return "NO\n";
            char tmp = s.top();
            if (!isMatched(tmp, c))
                return "NO\n";
            s.pop();
        }
    }
    if (s.empty())
        return "YES\n";
    else
        return "NO\n";
}
void __vippro__()
{
    string str;
    cin >> str;
    cout << isBalanced(str);
}

__ducsjukap__()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    int T;
    cin >> T;
    dr(T, T, 0)
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro