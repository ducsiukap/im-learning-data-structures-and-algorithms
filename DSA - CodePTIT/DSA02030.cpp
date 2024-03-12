#include <iostream>
using namespace std;

void input(char &c, int &n, char *&ans)
{
    cin >> c >> n;
    ans = new char[n + 1];
    ans[0] = 'A';
}

void show(char *ans, int &n)
{
    for (int i = 1; i <= n; ++i)
        cout << ans[i];
    cout << '\n';
}

void Try(char *ans, char &c, int &n, int i)
{
    for (char x = ans[i - 1]; x <= c; ++x)
    {
        ans[i] = x;
        if (i == n)
            show(ans, n);
        else
            Try(ans, c, n, i + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char c;
    int n;
    char *ans;
    input(c, n, ans);
    Try(ans, c, n, 1);
    delete[] ans;
    return 0;
}