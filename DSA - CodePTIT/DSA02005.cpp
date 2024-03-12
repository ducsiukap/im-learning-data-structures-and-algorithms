#include <iostream>
using namespace std;

void input(string &s, int &n, int *&ans, bool *&unused)
{
    cin >> s;
    n = s.size();
    ans = new int[n];
    unused = new bool[n];
    for (int i = 0; i < n; ++i)
        unused[i] = 1;
    --n;
}

void show(string &s, int *ans, int &n)
{
    for (int i = 0; i <= n; ++i)
        cout << s[ans[i]];
    cout << ' ';
}

void Try(string &s, int *ans, int &n, int i, bool *unused)
{
    for (int j = 0; j <= n; ++j)
    {
        if (unused[j])
        {
            ans[i] = j;
            unused[j] = 0;
            if (i == n)
                show(s, ans, n);
            else
                Try(s, ans, n, i + 1, unused);
            unused[j] = 1;
        }
    }
}

int main()
{
    int t, n;
    string s;
    int *ans;
    bool *unused;
    cin >> t;
    do
    {
        input(s, n, ans, unused);
        Try(s, ans, n, 0, unused);
        cout << '\n';
        delete[] ans, unused; // free memory
    } while (--t);
}