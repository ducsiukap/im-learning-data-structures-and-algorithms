// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (int i = a; i < b; ++i)
#define fd(i, a, b) for (int i = a; i <= b; ++i)
#define dr(i, a, b) for (int i = a; i > b; --i)
#define dd(i, a, b) for (int i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

class Graph
{
private:
    int n, A[100][100];
    bool chuaxet[100];

public:
    int s, t, truoc[100];
    void readdata();
    void init();
    void DFS(int);
    void BFS(int);
    void Ghi_Nhan_Duong_Di(int, int);
};

void Graph::readdata()
{
    cin >> n >> s >> t;
    fd(i, 1, n) fd(j, 1, n) cin >> A[i][j];
}

void Graph::init()
{
    fd(i, 1, n)
    {
        chuaxet[i] = true;
        truoc[i] = 0;
    }
}

void Graph::DFS(int u)
{
    stack<int> st;

    st.push(u);
    chuaxet[u] = false;

    while (!st.empty())
    {
        int v = st.top();
        st.pop();

        fd(k, 1, n) if (A[v][k] && chuaxet[k])
        {
            truoc[k] = v;

            st.push(v);
            st.push(k);
            chuaxet[k] = false;

            break;
        }
    }
}

void Graph::BFS(int u)
{
    queue<int> q;

    q.push(u);
    chuaxet[u] = false;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        fd(k, 1, n) if (A[v][k] && chuaxet[k])
        {
            truoc[k] = v;

            q.push(k);
            chuaxet[k] = false;
        }
    }
}

void Graph::Ghi_Nhan_Duong_Di(int s, int t)
{
    int u = t;
    while (truoc[u])
    {
        cout << ' ' << u;
        u = truoc[u];
    }

    cout << ' ' << s << '\n';
}

void __vippro__()
{
    Graph G;
    G.readdata();

    G.init();
    G.DFS(G.s);

    if (G.truoc[G.t])
    {
        cout << "DFS path:";
        G.Ghi_Nhan_Duong_Di(G.s, G.t);

        G.init();
        G.BFS(G.s);
        cout << "BFS path:";
        G.Ghi_Nhan_Duong_Di(G.s, G.t);
    }
    else
        cout << "no path\n";
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