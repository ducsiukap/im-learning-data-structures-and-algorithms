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
#define fr(i, a, b) for (int i = a; i < b; ++i)
#define fd(i, a, b) for (int i = a; i <= b; ++i)
#define dr(i, a, b) for (int i = a; i > b; --i)
#define dd(i, a, b) for (int i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

class Graph
{
private:
    int n, s, A[100][100], X[100];
    bool chuaxet[100];

public:
    void readdata();
    void init();
    void Hmt_Try(int);
    void Hamilton_Cycle(int);
    int getS() { return s; }
};

void Graph::readdata()
{
    cin >> n >> s;
    fd(i, 1, n) fd(j, 1, n) cin >> A[i][j];
}

void Graph::init() { fd(i, 1, n) chuaxet[i] = true; }

void Graph::Hamilton_Cycle(int u)
{
    init();

    X[1] = u;
    chuaxet[u] = false;

    Hmt_Try(2);
}

void Graph::Hmt_Try(int i)
{
    fd(u, 1, n) if (A[X[i - 1]][u])
    {
        if (i == n + 1 && u == X[1])
        {
            X[i] = u;
            fd(j, 1, n + 1) cout << X[j] << '\n';
            cout << '\n';
        }
        else if (chuaxet[u])
        {
            X[i] = u;
            chuaxet[u] = false;
            Hmt_Try(i + 1);
            chuaxet[u] = true;
        }
    }
}

void __vippro__()
{
    Graph G;
    G.readdata();
    G.Hamilton_Cycle(G.getS());
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