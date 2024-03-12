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

void Doidau(char &c)
{
    if (c == '+')
        c = '-';
    else
        c = '+';
}
void __vippro__()
{

    string s, res;
    stack<char> st;
    cin >> s;
    res = "";
    for (char &c : s)
    {
        if (c == ')')
        {
            res = "";
            while (st.top() != '(')
            {
                res = st.top() + res;
                st.pop();
            }
            st.pop();
            if (!st.empty() && st.top() == '-')
            {
                for (char &i : res)
                {
                    if (i == '-')
                        i = '+';
                    else if (i == '+')
                        i = '-';
                    st.push(i);
                }
            }
            else
                for (char &i : res)
                    st.push(i);
        }
        else
            st.push(c);
    }
    res = "\n";
    while (!st.empty())
    {
        res = st.top() + res;
        st.pop();
    }
    cout << res;
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