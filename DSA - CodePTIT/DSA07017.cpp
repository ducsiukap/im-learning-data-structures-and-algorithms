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

void __vippro__()
{

    stack<int> gr, sm;
    int n, i;
    cin >> n;
    vector<int> v(n), G(n), S(n);
    fr(i, 0, n) cin >> v[i];
    dd(i, n - 1, 0)
    {
        while (!gr.empty() && v[gr.top()] <= v[i])
            gr.pop();
        while (!sm.empty() && sm.top() >= v[i])
            sm.pop();
        if (gr.empty())
            G[i] = -1;
        else
            G[i] = gr.top();
        gr.push(i);
        if (sm.empty())
            S[i] = -1;
        else
            S[i] = sm.top();
        sm.push(v[i]);
    }
    fr(i, 0, n)
    {
        if (G[i] == -1)
            cout << G[i] << ' ';
        else
            cout << S[G[i]] << ' ';
    }
    cout << '\n';
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