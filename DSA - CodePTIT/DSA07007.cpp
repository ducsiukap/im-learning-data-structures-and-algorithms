// * Code by Ducsjukapvippro
// * dont cry bae =))
// * neu ngay mai khong den thi sao?

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;

#define __ducsjukap__ int main()
#define faster()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define run() \
    int T;    \
    cin >> T; \
    while (T--)
#define v(x) vector<x>
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define fi first
#define se second
#define pb(a) push_back(a)
#define fr(i, a, b) for (int i = a; i < b; ++i)
#define fe(i, a, b) for (int i = a; i <= b; ++i)
#define dr(i, a, b) for (int i = a; i > b; --i)
#define de(i, a, b) for (int i = a; i >= b; --i)
#define in(x, n) fr(i, 0, n) cin >> x[i]
#define out(x, n, sep) fr(i, 0, n) cout << x[i] << sep
#define reset(x, n, value) fr(i, 0, n) x[i] = value

void rewrite(string &s)
{
    stack<char> st1, st2;
    for (char &c : s)
    {
        if (isalpha(c))
            st1.push(c);
        else if (c == ')')
            st2.pop();
        else if (c == '(')
            st2.push(st1.top());
        else
        {
            if (!st2.empty() && st2.top() == '-')
            {
                if (c == '-')
                    c = '+';
                else if (c == '+')
                    c = '-';
            }
            st1.push(c);
        }
    }

    s = "";
    while (!st1.empty())
    {
        s = st1.top() + s;
        st1.pop();
    }
}

void __vippro__()
{
    string s1, s2;
    cin >> s1 >> s2;
    rewrite(s1);
    rewrite(s2);
    if (s1 == s2)
        cout << "YES\n";
    else
        cout << "NO\n";
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
