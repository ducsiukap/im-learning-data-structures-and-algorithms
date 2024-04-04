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
    int n, A[100][100];
    bool chuaxet[100];

public:
    void readdata();
    void init();
    int DFS(int);
    void Duyet_Tru();
};

void Graph::readdata()
{
    cin >> n;
    fd(i, 1, n) fd(j, 1, n) cin >> A[i][j];
}

void Graph::init() { fd(i, 1, n) chuaxet[i] = true; }

int Graph::DFS(int u)
{
    stack<int> st;
    int cnt;

    st.push(u);
    chuaxet[u] = false;
    cnt = 1;

    while (!st.empty())
    {
        int v = st.top();
        st.pop();

        fd(t, 1, n) if (A[v][t] && chuaxet[t])
        {
            st.push(v);
            st.push(t);
            chuaxet[t] = false;
            ++cnt;
            break;
        }
    }

    return cnt;
}

void Graph::Duyet_Tru()
{
    init();
    chuaxet[1] = false;
    if (DFS(2) != n - 1)
        cout << 1 << ' ';

    fd(i, 2, n)
    {
        init();
        chuaxet[i] = false;
        if (DFS(1) != n - 1)
            cout << i << ' ';
    }

    cout << '\n';
}

void __vippro__()
{
    Graph G;
    G.readdata();

    G.Duyet_Tru();
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