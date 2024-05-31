// * Code by Ducsjukapvippro
// * dont cry bae =))
// * neu ngay mai khong den thi sao?

// problem: https://www.geeksforgeeks.org/rat-in-a-maze/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

#define __ducsjukap__ int main()
#define faster()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define run() \
    int T;    \
    cin >> T; \
    while (T--)
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define fi first
#define se second
#define pb(a) push_back(a)
#define fr(i, a, b) for (int i = a; i < b; ++i)
#define fe(i, a, b) for (int i = a; i <= b; ++i)
#define dr(i, a, b) for (int i = a; i > b; --i)
#define de(i, a, b) for (int i = a; i >= b; --i)
#define in(x, n) fr(itr, 0, n) cin >> x[itr]
#define out(x, n, sep) fr(itr, 0, n) cout << x[itr] << sep
#define reset(x, n, value) fr(itr, 0, n) x[itr] = value

char direction[] = "RULD";
int x[] = {1, 0, -1, 0};
int y[] = {0, -1, 0, 1};
int n; // sz of maze

vt(string) all_path;

void Try(vt(vt(int)) & maze, int X, int Y, string path)
{
    if (X < 0 || X >= n || Y < 0 || Y >= n || maze[Y][X] != 1)
        return;

    if (X == Y && Y == n - 1)
    {
        all_path.push_back(path);
        return;
    }

    maze[Y][X] = 0;
    fr(i, 0, 4)
        Try(maze, X + x[i], Y + y[i], path + direction[i]);
    maze[Y][X] = 1;
}

void __vippro__()
{
    cin >> n;

    vt(vt(int)) maze(n, vt(int)(n));

    for (vt(int) & v : maze)
        for (int &i : v)
            cin >> i;

    if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0 || (maze[n - 2][n - 1] == 0 && maze[n - 1][n - 2] == 0))
    {
        cout << -1 << '\n';
        return;
    }

    all_path.clear();
    Try(maze, 0, 0, "");

    sort(all(all_path));

    if (all_path.empty())
        cout << -1;
    else
        out(all_path, sz(all_path), ' ');
    cout << '\n';
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
