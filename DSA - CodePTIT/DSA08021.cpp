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

struct next_position
{
    int row, col, route_length;
    next_position(int a, int b, int c) : row(a), col(b), route_length(c) {}
};

void __vippro__()
{
    int n, m, next_pos;
    queue<next_position> q;
    next_position np = next_position(0, 0, 0);

    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (vector<int> &i : v)
        for (int &j : i)
            cin >> j;

    --n;
    --m;
    q.push(next_position(0, 0, 0));

    while (!q.empty())
    {
        np = q.front();
        q.pop();
        visited[np.row][np.col] = true;

        if (np.row == n && np.col == m)
        {
            cout << np.route_length << '\n';
            return;
        }

        next_pos = np.row + v[np.row][np.col];
        if (next_pos <= n && visited[next_pos][np.col] == false)
            q.push(next_position(next_pos, np.col, np.route_length + 1));

        next_pos = np.col + v[np.row][np.col];
        if (next_pos <= m && visited[np.row][next_pos] == false)
            q.push(next_position(np.row, next_pos, np.route_length + 1));
    }

    cout << "-1\n";
}

__ducsjukap__()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    dr(T, T, 0)
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro