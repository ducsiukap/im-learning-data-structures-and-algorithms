#include <iostream>
#include <vector>
using namespace std;

bool count_char(string &s, int &i, int &n)
{
    int D = 0;
    for (int j = 0; j <= i; ++j)
        D += (s[j] == 'D');
    return (D <= n && i - D + 1 <= n);
}

void Try(vector<vector<int>> &v, int &n, string &s, bool &res, int i, int r, int c)
{
    int *dr;
    for (int j = 0; j < 2; ++j)
    {
        if (j)
        {
            s[i] = 'R';
            dr = &c;
        }
        else
        {
            s[i] = 'D';
            dr = &r;
        }
        ++(*dr);
        if (r == c && r == n)
        {
            cout << s << ' ';
            res = true;
        }
        else if (v[r][c] && count_char(s, i, n))
        {
            if ((v[r][c + 1] || v[r + 1][c]))
                Try(v, n, s, res, i + 1, r, c);
        }
        --(*dr);
    }
}

void input(vector<vector<int>> &v, int &n, string &s)
{
    cin >> n;
    v.resize(n + 1, vector<int>(n + 1));
    int i, j;
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            cin >> v[i][j];
    for (i = 0; i < n; ++i)
        v[i][n] = 0;
    for (j = 0; j < n; ++j)
        v[n][j] = 0;
    --n;
    s.resize(2 * n);
}

void free_memory(vector<vector<int>> &v, string &s)
{
    for (int i = 0; i < v.size(); ++i)
        v[i].clear();
    v.clear();
    s.clear();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    string s;
    bool have;
    vector<vector<int>> v;
    cin >> t;
    do
    {
        input(v, n, s);
        if (!v[n][n])
            cout << "-1\n";
        else
        {
            have = 0;
            Try(v, n, s, have, 0, 0, 0);
            if (!have)
                cout << "-1";
            cout << '\n';
        }
        free_memory(v, s);
    } while (--t);
    return 0;
}