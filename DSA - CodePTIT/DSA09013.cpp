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

bool dfs(vt(vt(int)) & v, int &n)
{
    vt(bool) check(n + 1, false);
    stack<int> st;
    st.push(1);
    check[1] = true;
    while (!st.empty())
    {
        int s = st.top();
        st.pop();
        fe(i, 1, n) if (v[s][i] && !check[i])
        {
            st.push(s);
            st.push(i);
            check[i] = true;
            break;
        }
    }

    fe(i, 1, n) if (!check[i]) return true;
    return false;
}

void __vippro__()
{
    int n, e;
    cin >> n >> e;

    vt(vt(int)) v(n + 1, vt(int)(n + 1, 0));
    vector<pair<int, int>> vp(e);

    for (pair<int, int> &p : vp)
    {
        cin >> p.fi >> p.se;
        v[p.fi][p.se] = v[p.se][p.fi] = 1;
    }

    vector<pair<int, int>> ans;
    fr(i, 0, e)
    {
        v[vp[i].fi][vp[i].se] = v[vp[i].se][vp[i].fi] = 0;
        if (dfs(v, n))
            ans.push_back(vp[i]);
        v[vp[i].fi][vp[i].se] = v[vp[i].se][vp[i].fi] = 1;
    }

    sort(all(ans));
    for (pair<int, int> &p : ans)
        cout << p.fi << ' ' << p.se << ' ';
    cout << '\n';
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
