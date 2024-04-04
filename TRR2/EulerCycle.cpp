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
    int n, s, A[100][100];

public:
    void readdata();
    void Euler_Cycle(int);
    int getS() { return s; }
};

void Graph::readdata()
{
    cin >> n >> s;
    fd(i, 1, n) fd(j, 1, n) cin >> A[i][j];
}

void Graph::Euler_Cycle(int u)
{
    stack<int> st, EC;

    st.push(u);

    while (!st.empty())
    {
        int t = st.top();
        bool neighbour_t = false;

        fd(i, 1, n) if (A[t][i])
        {
            neighbour_t = true;
            st.push(i);
            A[t][i] = A[i][t] = 0;
            break;
        }

        if (neighbour_t == false)
        {
            st.pop();
            EC.push(t);
        }
    }

    while (!EC.empty())
    {
        cout << EC.top() << ' ';
        EC.pop();
    }
}

void __vippro__()
{
    Graph G;
    G.readdata();
    G.Euler_Cycle(G.getS());
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