#include <iostream>
#include <vector>
using namespace std;

void input(vector<vector<int>> &v, int &n, string &s)
{
    cin >> n;
    v.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> v[i][j];
    --n;
    s.resize(2 * n);
}

void free_memory(vector<vector<int>> &v, int &n, string &s)
{
    s.clear();
    for (int i = 0; i <= n; ++i)
        v[i].clear();
    v.clear();
}

void Try(vector<vector<int>> &v, string &s, int &n, bool &ok, int i, int r, int c)
{
    if (r == n && c == n)
    {
        ok = true;
        cout << s << ' ';
    }
    if (r < n && v[r + 1][c])
    {
        s[i] = 'D';
        Try(v, s, n, ok, i + 1, r + 1, c);
    }
    if (c < n && v[r][c + 1])
    {
        s[i] = 'R';
        Try(v, s, n, ok, i + 1, r, c + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> v;
    int t, n;
    string ans;
    bool ok;
    cin >> t;
    do
    {
        input(v, n, ans);
        if (v[0][0] && v[n][n])
        {
            ok = false;
            Try(v, ans, n, ok, 0, 0, 0);
            if (!ok)
                cout << -1;
            cout << '\n';
        }
        else
            cout << "-1\n";
        free_memory(v, n, ans);
    } while (--t);
    return 0;
}