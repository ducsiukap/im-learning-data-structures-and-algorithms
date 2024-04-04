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

#define Max 100
class Graph
{
public:
    int n, A[Max][Max];
    bool unused[Max];
    void readdata()
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                cin >> A[i][j];
    }
    void init()
    {
        for (int i = 1; i <= n; ++i)
            unused[i] = true;
    }
    void DFS(int &u)
    {
        stack<int> st;

        st.push(u);
        unused[u] = false;
        cout << u << ' ';

        while (!st.empty())
        {
            int s = st.top();
            st.pop();

            for (int t = 1; t <= n; ++t)
                if (A[s][t] && unused[t])
                {
                    st.push(s);
                    st.push(t);
                    unused[t] = false;
                    cout << t << ' ';
                    break;
                }
        }

        cout << '\n';
    }

    void DemThanhPhanLienThong()
    {
        init();
        int cnt = 0;

        for (int i = 1; i <= n; ++i)
            if (unused[i])
            {
                ++cnt;

                cout << "Thanh phan lien thong thu " << cnt << ": ";
                DFS(i);
            }
    }
};

void __vippro__()
{
    Graph G;
    G.readdata();
    G.DemThanhPhanLienThong();
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
// * Code by Ducsjukapvippro