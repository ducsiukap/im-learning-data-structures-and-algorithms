#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

struct Edge // (u, v) in E
{
    int st, en; // dau, cuoi
    int w;      // trong so
};

bool cmp(Edge &a, Edge &b)
{
    if (a.w == b.w)
        if (a.st == b.st)
            return a.en < b.en;
        else
            return a.st < b.st;
    else
        return a.w < b.w;
}

class Graph
{
private:
    int n, A[100][100];
    bool chuaxet[100];

    int Ecnt;     // so luong cac canh
    Edge E[5100]; // tap hop cac canh

public:
    void readdata();
    void get_set_of_edge();
    void init();
    bool DFS(int[100][100], int, int);
    void Kruskal();
};

void Graph::readdata()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> A[i][j];
}

void Graph::get_set_of_edge()
{
    Ecnt = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (A[i][j])
            {
                E[Ecnt].st = i;
                E[Ecnt].en = j;
                E[Ecnt].w = A[i][j];

                ++Ecnt;
            }

    sort(E, E + Ecnt, cmp);
}

void Graph::init()
{
    for (int i = 1; i <= n; ++i)
        chuaxet[i] = true;
}

bool Graph::DFS(int T[100][100], int st, int en)
{
    init();
    stack<int> stk;

    stk.push(st);
    chuaxet[st] = false;
    while (!stk.empty())
    {
        int u = stk.top();
        stk.pop();

        for (int v = 1; v <= n; ++v)
            if (T[u][v] && chuaxet[v])
            {
                stk.push(u);
                stk.push(v);
                chuaxet[v] = false;
                break;
            }
    }

    return chuaxet[en];
}

void Graph::Kruskal()
{
    get_set_of_edge();

    int dH = 0;
    queue<Edge> q; // luu cac canh cua cay khung nho nhat theo Kruskal

    int T[100][100]; // do thi cac canh trong cay khung Kruskal
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            T[i][j] = 0;

    for (int i = 0; i < Ecnt; ++i)
    {
        if (DFS(T, E[i].st, E[i].en))
        {
            q.push(E[i]);
            dH += E[i].w;
            T[E[i].st][E[i].en] = T[E[i].en][E[i].st] = E[i].w;
        }

        if (q.size() == n - 1)
            break;
    }

    // hien thi cay khung nho nhat theo Kruskal
    cout << "dH = " << dH << '\n';
    while (!q.empty())
    {
        cout << q.front().st << ' ' << q.front().en << '\n';
        q.pop();
    }
}

int main()
{
    Graph G;
    G.readdata();
    G.Kruskal();

    return 0;
}