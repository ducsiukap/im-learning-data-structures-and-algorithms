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
#define vt(x) vector<x>
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

void rebuilt_expression(string &Exp)
{
    stack<char> str, opr;
    Exp = '+' + Exp;
    str.push('+');

    for (char &c : Exp)
    {
        if (isalpha(c))
            str.push(c);
        else if (c == '+' || c == '-')
        {
            if (opr.empty() || opr.top() == '+')
                str.push(c);
            else
                str.push((c == '+' ? '-' : '+'));
        }
        else if (c == '(')
            opr.push(str.top());
        else
            opr.pop();
    }

    Exp = "";
    while (str.size() != 2)
    {
        Exp = str.top() + Exp;
        str.pop();
    }
}

void __vippro__()
{
    string s1, s2;
    cin >> s1 >> s2;

    rebuilt_expression(s1);
    rebuilt_expression(s2);
    // cout << s1 << ' ' << s2 << '\n';
    cout << (s1 == s2 ? "YES\n" : "NO\n");
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
