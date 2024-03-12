#include <iostream>
using namespace std;

void input(char &D, bool *&unused, int &n)
{
    cin >> D;
    n = D - 'A';
    unused = new bool[n + 1];
    for (int i = 0; i <= n; ++i)
        unused[i] = true;
}

bool check(string &s, int &i)
{
    for (int j = 1; j < i; ++j)
    {
        if (s[j] == 'A')
            if (s[j - 1] != 'E' && s[j + 1] != 'E')
                return false;
        if (s[j] == 'E')
            if (s[j - 1] != 'A' && s[j + 1] != 'A')
                return false;
    }
    return true;
}

void Try(string &s, bool *unused, int &n, int i)
{
    for (int j = 0; j <= n; ++j)
    {
        if (unused[j])
        {
            s.push_back('A' + j);
            unused[j] = false;
            bool ok = check(s, i);
            if (ok)
            {
                if (i == n)
                    cout << s << '\n';
                else
                    Try(s, unused, n, i + 1);
            }
            s.pop_back();
            unused[j] = true;
        }
    }
}

int main()
{
    char D;
    bool *unused;
    int n;
    string ans;
    input(D, unused, n);
    Try(ans, unused, n, 0);
    delete[] unused;
    return 0;
}