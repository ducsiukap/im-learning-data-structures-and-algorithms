#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Graph
{
private:
    int n, s, A[100][100];
    bool chuaxet[100];

public:
    void readdata();
    void init();
    void DFS(queue<int> &, int);
    void BFS(queue<int> &, int);
    void Tree_Graph(int);
    int getS() { return s; }
};

void Graph::readdata()
{
    cin >> n >> s;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> A[i][j];
}

void Graph::init()
{
    for (int i = 1; i <= n; ++i)
        chuaxet[i] = true;
}

void Graph::DFS(queue<int> &q, int u)
{
    stack<int> st;

    st.push(u);
    chuaxet[u] = false;

    while (!st.empty())
    {
        int v = st.top();
        st.pop();

        for (int t = 1; t <= n; ++t)
            if (A[v][t] && chuaxet[t])
            {
                q.push(v);
                q.push(t);

                st.push(v);
                st.push(t);
                chuaxet[t] = false;
                break;
            }
    }
}

void Graph::BFS(queue<int> &q, int u)
{
    queue<int> qe;

    qe.push(u);
    chuaxet[u] = false;
    while (!qe.empty())
    {
        int v = qe.front();
        qe.pop();

        for (int t = 1; t <= n; ++t)
            if (A[v][t] && chuaxet[t])
            {
                q.push(v);
                q.push(t);

                qe.push(t);
                chuaxet[t] = false;
            }
    }
}

void Graph::Tree_Graph(int u)
{
    queue<int> T;

    init();
    DFS(T, s);
    cout << "DFS tree\n";
    while (!T.empty())
    {
        cout << T.front() << ' ';
        T.pop();
        cout << T.front() << '\n';
        T.pop();
    }

    init();
    BFS(T, s);
    cout << "BFS tree\n";
    while (!T.empty())
    {
        cout << T.front() << ' ';
        T.pop();
        cout << T.front() << '\n';
        T.pop();
    }
    cout << '\n';
}

int main()
{
    Graph G;
    G.readdata();
    G.Tree_Graph(G.getS());

    return 0;
}