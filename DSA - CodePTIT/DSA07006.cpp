// * Code by Ducsjukapvippro
// * dont cry bae =))
// * neu ngay mai khong den thi sao?

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>

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

// set<string> ans;
void fixup_string(set<string> &ans, string &s)
{
    stack<int> st;
    vector<pair<int, int>> vp;

    fr(i, 0, sz(s))
    {
        if (s[i] == '(')
            st.push(i);
        else if (s[i] == ')')
        {
            vp.push_back(make_pair(st.top(), i));
            st.pop();
        }
    }

    for (pair<int, int> &p : vp)
    {
        string res = s;
        res.erase(p.second, 1);
        res.erase(p.first, 1);
        if (ans.find(res) == ans.end())
        {
            ans.insert(res);
            fixup_string(ans, res);
        }
    }
}

void __vippro__()
{
    string s;
    cin >> s;
    set<string> ans;
    fixup_string(ans, s);
    for (set<string>::iterator it = ans.begin(); it != ans.end(); ++it)
        cout << *it << '\n';
}

__ducsjukap__
{
    faster();
    // run()
    __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro