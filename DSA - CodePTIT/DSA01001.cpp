#include <iostream>
using namespace std;
int main()
{
    int t;
    string s;
    cin >> t;
    while (t)
    {
        --t;
        cin >> s;
        int i = s.size();
        while ((--i >= 0) && s[i] == '1')
            s[i] = '0';
        if (i != -1)
            s[i] = '1';
        cout << s << '\n';
    }
    system("pause");
}