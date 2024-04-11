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

class Graph
{
private:
    int n;
    vector<vector<int>> v;
    vector<bool> unused;

public:
    void readdata();
    void init();
    void DFS(int);
};

void Graph::readdata()
{
    cin >> n;
    v.resize(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> v[i][j];
}

void Graph::init() { unused.resize(n + 1, true); }

void Graph::DFS(int u)
{
    stack<int> st;

    st.push(u);
    unused[u] = false;
    cout << "\nDuyet dinh : " << u;

    while (!st.empty())
    {
        int s = st.top();
        st.pop();

        for (int i = 1; i <= n; ++i)
        {
            if (v[s][i] && unused[i])
            {
                st.push(s);
                st.push(i);

                unused[i] = false;
                cout << "\nDuyet dinh : " << i;

                break;
            }
        }
    }
}

void __vippro__()
{
    Graph G;
    G.readdata();
    G.init();
    G.DFS(1);
    cout << '\n';
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