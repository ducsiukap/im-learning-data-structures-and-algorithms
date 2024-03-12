#include <iostream>
#include <string>
using namespace std;
#define AH "AH"

bool check(string &s, const int &i, int &n)
{
    if (i == n && s[n] == 'H')
        return false;
    for (int j = 1; j <= i;)
    {
        if (s[j] == 'H')
        {
            if (s[j] == s[j - 1])
                return false;
            ++j;
        }
        else
            j += 2;
    }
    return true;
}

void Try(string &s, int &n, const int &i)
{
    for (int j = 0; j <= 1; ++j)
    {
        s[i] = AH[j];
        bool ok = check(s, i, n);
        if (ok)
        {
            if (i == n)
                cout << s << '\n';
            else
                Try(s, n, i + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    string s;
    cin >> t;
    while (t)
    {
        --t;
        cin >> n;
        s.resize(n);
        s[0] = 'H';
        --n;
        Try(s, n, 1);
    }
    return 0;
}