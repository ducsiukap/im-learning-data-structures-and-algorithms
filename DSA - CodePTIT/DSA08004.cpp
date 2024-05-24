// * Code by Ducsjukapvippro
// * dont cry bae =))
// * neu ngay mai khong den thi sao?

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

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

void __vippro__()
{
    int k;
    string s;
    cin >> k >> s;

    vt(int) v(26, 0);
    for (char &c : s)
        ++v[c - 'A'];

    priority_queue<int> pq;
    fr(i, 0, 26) if (v[i]) pq.push(v[i]);
    while (k && !pq.empty())
    {
        int top = pq.top();
        pq.pop();
        --top;
        if (top)
            pq.push(top);
        --k;
    }
    ll res = 0;
    while (!pq.empty())
    {
        ll top = pq.top();
        pq.pop();
        top *= top;
        res += top;
    }
    cout << res << '\n';
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
