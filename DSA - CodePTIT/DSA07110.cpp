// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i <= b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;
map<char, char> mp = {make_pair(']', '['), make_pair('}', '{'), make_pair(')', '(')};
void __vippro__()
{
    stack<char> st;
    string s;
    cin >> s;
    for (char &c : s)
    {
        if (c == '{' || c == '(' || c == '[')
            st.push(c);

        else
        {
            if (st.empty() || mp[c] != st.top())
            {
                cout << "NO\n";
                return;
            }
            else
                st.pop();
        }
    }
    cout << "YES\n";
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