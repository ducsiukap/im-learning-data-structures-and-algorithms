#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
    int st, en;
    int w;
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
    int n, s, A[100][100];
    bool vH[100], v[100];

    vector<Edge> E;
    int Ecnt;

public:
    void readdata();
    void init(int);
    void get_set_of_edge();
    void Prims(int);
    int getS() { return s; }
};

void Graph::readdata()
{
    cin >> n >> s;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> A[i][j];
}

void Graph::init(int u)
{
    for (int i = 1; i <= n; ++i)
    {
        vH[i] = false;
        v[i] = true;
    }

    vH[u] = true;
    v[u] = false;
}

void Graph::get_set_of_edge()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (A[i][j])
            {
                Edge e;
                e.st = i;
                e.en = j;
                e.w = A[i][j];

                E.push_back(e);
            }

    sort(E.begin(), E.end(), cmp);
}

void Graph::Prims(int u)
{
    init(u);
    get_set_of_edge();

    int dH = 0;
    queue<Edge> T;

    for (int i = 1; i <= n - 1; ++i)
    {
        for (int j = 0; j < E.size(); ++j)
            if (vH[E[j].st] && v[E[j].en] || vH[E[j].en] && v[E[j].st])
            {
                vH[E[j].st] = vH[E[j].en] = true;
                v[E[j].st] = v[E[j].en] = false;

                T.push(E[j]);
                dH += E[j].w;

                E.erase(E.begin() + j);
                break;
            }
    }

    cout << "dH = " << dH << '\n';
    while (!T.empty())
    {
        Edge e = T.front();
        T.pop();

        cout << e.st << ' ' << e.en << '\n';
    }
}

int main()
{
    Graph G;
    G.readdata();

    G.Prims(G.getS());

    return 0;
}