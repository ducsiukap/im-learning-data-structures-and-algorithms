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
#define in(x, n) fr(itr, 0, n) cin >> x[itr]
#define out(x, n, sep) fr(itr, 0, n) cout << x[itr] << sep
#define reset(x, n, value) fr(itr, 0, n) x[itr] = value

bool dfs(vt(vt(int)) & ke, int &n, int &u, int &v)
{
    stack<int> st;
    vt(bool) unused(n + 1, true);

    st.push(u);
    unused[u] = false;

    while (!st.empty())
    {
        int s = st.top();
        st.pop();

        for (int &t : ke[s])
        {
            if (t == v)
                return true;
            if (unused[t])
            {
                st.push(s);
                st.push(t);
                unused[t] = false;
                break;
            }
        }
    }

    return false;
}
void __vippro__()
{
    int n, m, q;
    cin >> n >> m;

    int u, v;
    vt(vt(int)) ke(n + 1);
    fr(i, 0, m)
    {
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }

    cin >> q;
    while (q--)
    {
        cin >> u >> v;
        if (dfs(ke, n, u, v))
            cout << "YES";
        else
            cout << "NO";
        cout << '\n';
    }
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
