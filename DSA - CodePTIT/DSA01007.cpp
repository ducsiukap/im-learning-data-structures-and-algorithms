#include <iostream>
#include <string>
using namespace std;

bool sinh(string &s, int &n)
{
    int i = n - 1;
    while (i >= 0 && s[i] == 'B')
    {
        s[i] = 'A';
        --i;
    }
    if (i == -1)
        return false;
    s[i] = 'B';
    return true;
}

int main()
{
    int t, n;
    string s;
    cin >> t;
    while (t)
    {
        --t;
        cin >> n;
        s = "";
        for (int i = 0; i < n; ++i)
            s += 'A';
        cout << s << ' ';
        while (sinh(s, n))
            cout << s << ' ';
        cout << '\n';
    }
    return 0;
}