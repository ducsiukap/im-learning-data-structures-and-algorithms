#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d;
    string sa, sb;
    a = b = c = d = 0;
    cin >> sa >> sb;
    for (int i = 0; i < sa.size(); ++i)
    {
        a = a * 10 + sa[i] - '0';
        c = c * 10 + sa[i] - '0';
        a -= (sa[i] == '6');
        c += (sa[i] == '5');
    }
    for (int i = 0; i < sb.size(); ++i)
    {
        b = b * 10 + sb[i] - '0';
        d = d * 10 + sb[i] - '0';
        b -= (sb[i] == '6');
        d += (sb[i] == '5');
    }
    cout << a + b << ' ' << c + d << '\n';
    system("pause");
}