// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
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
    void BFS(int);
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

void Graph::BFS(int u)
{
    queue<int> q;

    q.push(u);
    unused[u] = false;

    while (!q.empty())
    {
        int s = q.front();
        q.pop();

        cout << "\nDuyet dinh : " << s; // do smt

        for (int t = 1; t <= n; ++t)
            if (v[s][t] && unused[t])
            {
                q.push(t);
                unused[t] = false;
            }
    }
}

void __vippro__()
{
    Graph G;
    G.readdata();
    G.init();
    G.BFS(1);
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