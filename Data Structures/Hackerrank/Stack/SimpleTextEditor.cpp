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
    int q, pos, prevOps, Ops;
    string tmp;
    stack<string> st;
    int change = 0;
    st.push("");
    cin >> q;
    prevOps = 3;
    while (q--)
    {
        cin >> Ops;
        switch (Ops)
        {
        case 1:
            cin >> tmp;
            tmp = st.top() + tmp;
            st.push(tmp);
            ++change;
            break;
        case 2:
            cin >> pos;
            tmp = st.top();
            while (!tmp.empty() && pos--)
                tmp.erase(tmp.end() - 1);
            st.push(tmp);
            ++change;
            break;
        case 3:
            cin >> pos;
            if (pos <= st.top().size())
                cout << st.top()[pos - 1];
            cout << '\n';
            break;
        default:
            if (change)
            {
                --change;
                st.pop();
            }
        }
    }
}

__ducsjukap__()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    // cin >> T;
    dr(T, 1, 0)
        __vippro__();
    return 0;
}