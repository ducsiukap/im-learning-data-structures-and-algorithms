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
    void readdata();
    void init();
    int BFS(int);
    bool strongly_connected();
};

void Graph::readdata()
{
    cin >> n;
    fd(i, 1, n) fd(j, 1, n) cin >> A[i][j];
}

void Graph::init() { fd(i, 1, n) chuaxet[i] = true; }

int Graph::BFS(int u)
{
    queue<int> q;
    int cnt;

    q.push(u);
    chuaxet[u] = 0;
    cnt = 1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        fd(i, 1, n) if (A[v][i] && chuaxet[i])
        {
            q.push(i);
            chuaxet[i] = false;
            ++cnt;
        }
    }

    return cnt;
}

bool Graph::strongly_connected()
{
    fd(i, 1, n)
    {
        init();
        if (BFS(i) != n)
            return false;
    }

    return true;
}

void __vippro__()
{
    Graph G;
    G.readdata();

    if (G.strongly_connected())
        cout << "strongly connected\n";
    else
        cout << "not strongly connected\n";
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