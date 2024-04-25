// * Code by Ducsjukapvippro
// * dont cry bae =))
// * neu ngay mai khong den thi sao?

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
#define v(x) vector<x>
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define fi first
#define se second
#define pb(a) push_back(a)
#define fr(i, a, b) for (int i = a; i < b; ++i)
#define fe(i, a, b) for (int i = a; i <= b; ++i)
#define dr(i, a, b) for (int i = a; i > b; --i)
#define de(i, a, b) for (int i = a; i >= b; --i)
#define in(x, n) fe(i, 1, n) cin >> x[i]
#define out(x, n, sep) fr(i, 0, n) cout << x[i] << sep
#define reset(x, n, value) fe(i, 1, n) x[i] = value

int n;
int A[10][10];
bool visited[10][10];
int x[] = {1, 0, -1, 0};
int y[] = {0, -1, 0, 1};
string direct = "RULD";
v(string) route;

void Try(int r, int c, string path)
{
    if (r == c && r == n)
        route.push_back(path);
    else if (r < 1 || c < 1 || r > n || c > n || A[r][c] == 0 || visited[r][c])
        return;
    else
    {
        visited[r][c] = true;
        fr(i, 0, 4)
        {
            path += direct[i];
            Try(r + y[i], c + x[i], path);
            path.erase(path.end() - 1);
        }
        visited[r][c] = false;
    }
}

void __vippro__()
{
    cin >> n;
    fe(j, 1, n) in(A[j], n);

    if (A[n][n] == 0 || (A[n - 1][n] == 0 && A[n][n - 1] == 0))
        cout << "-1\n";
    else
    {
        fe(j, 1, n) reset(visited[j], n, false);
        route.clear();

        Try(1, 1, "");

        if (sz(route) == 0)
            cout << "-1\n";
        else
        {
            sort(all(route));
            out(route, sz(route), ' ');
            cout << '\n';
        }
    }
}

__ducsjukap__
{
    // faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
