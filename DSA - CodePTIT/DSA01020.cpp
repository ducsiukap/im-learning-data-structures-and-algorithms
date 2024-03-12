#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, i;
    string s;
    cin >> t;
    while (t)
    {
        --t;
        cin >> s;
        int i = s.size();
        while (--i >= 0)
            if (s[i] == '0')
                s[i] = '1';
            else
            {
                s[i] = '0';
                break;
            }
        cout << s << '\n';
    }
    return 0;
}