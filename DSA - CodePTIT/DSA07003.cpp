// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i <= b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

bool check(string &s, int i, int j)
{
    if (j - i < 3)
        return false;
    else
    {
        while (i < j)
        {
            if (s[i] == '-' || s[i] == '+' || s[i] == '*' || s[i] == '/')
                return true;
            ++i;
        }
        return false;
    }
}

void __vippro__()
{
    string s;
    getline(cin, s);
    stack<int> open;
    int i;
    fr(i, 0, s.size())
    {
        if (s[i] == '(')
            open.push(i);
        else if (s[i] == ')')
        {
            if (open.empty())
            {
                cout << "No\n";
                return;
            }
            else
            {
                int tmp = open.top();
                if (check(s, tmp, i))
                {
                    s.erase(tmp, i + 1);
                    i = tmp;
                    open.pop();
                }
                else
                {
                    cout << "No\n";
                    return;
                }
            }
        }
    }
    cout << "Yes\n";
}

__ducsjukap__()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    scanf("\n");
    dr(T, T, 0)
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro