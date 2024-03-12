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
    int n, i, w; // w is width
    ll Smax, tmp;
    stack<pair<int, int>> st; // first is index, second is heigh
    cin >> n;
    vector<int> v(n);
    fr(i, 0, n) cin >> v[i];
    Smax = v[0];
    st.push(make_pair(0, v[0]));
    fr(i, 1, n)
    {
        if (st.top().second <= v[i])
            st.push(make_pair(i, v[i]));
        else
        {
            while (!st.empty() && st.top().second > v[i])
            {
                w = i - st.top().first;
                tmp = st.top().second;
                st.pop();
                Smax = max(Smax, tmp * w);
            }
            st.push(make_pair(i - w, v[i]));
        }
    }
    while (!st.empty())
    {
        w = i - st.top().first;
        tmp = st.top().second;
        st.pop();
        Smax = max(Smax, tmp * w);
    }
    cout << Smax << '\n';
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