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

int level(char &c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

void __vippro__()
{
    string s, res;
    cin >> s;
    res = "";
    stack<char> st;
    for (char &c : s)
    {
        if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (isalpha(c))
            res += c;
        else
        {
            while (!st.empty() && level(st.top()) >= level(c))
            {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        if (st.top() != '(')
            res += st.top();
        st.pop();
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