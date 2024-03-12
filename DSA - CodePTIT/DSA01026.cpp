#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool check(string &s)
{
    if (s.find("88") != string::npos || s.find("6666") != string::npos)
        return false;
    return true;
}

bool check2(string &s, const int &i)
{
    string tmp = s.substr(0, i + 1);
    if (tmp.find("88") != string::npos || tmp.find("6666") != string::npos)
        return false;
    return true;
}

string kt = "68";
void Try(string &s, int &n, const int &i)
{
    for (int j = 0; j <= 1; ++j)
    {
        s[i] = kt[j];
        if (i == n)
        {
            if (check(s))
                cout << s << '\n';
        }
        else if (check2(s, i))
            Try(s, n, i + 1);
    }
}

int main()
{
    int n;
    string s;
    cin >> n;
    s.resize(n);
    s[0] = '8';
    --n;
    s[n] = '6';
    --n;
    Try(s, n, 1);
    system("pause");
}