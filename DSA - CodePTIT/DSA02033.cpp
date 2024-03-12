#include <iostream>
#include <math.h>
using namespace std;

void input(int &n, int *&ans, bool *&unused)
{
    cin >> n;
    ans = new int[n];
    unused = new bool[n];
    for (int i = 0; i < n; ++i)
        unused[i] = 1;
    --n;
}

void show(int *ans, int &n)
{
    for (int i = 0; i <= n; ++i)
        cout << ans[i];
    cout << '\n';
}

bool check(int *ans, int &i)
{
    if (i > 0)
        return (abs(ans[i] - ans[i - 1]) != 1);
    return true;
}

void Try(int &n, int *ans, bool *unused, int i)
{
    for (int j = 0; j <= n; ++j)
    {
        if (unused[j])
        {
            unused[j] = false;
            ans[i] = j + 1;
            bool ok = check(ans, i);
            if (ok)
            {
                if (i == n)
                    show(ans, n);
                else
                    Try(n, ans, unused, i + 1);
            }
            unused[j] = true;
        }
    }
}

int main()
{
    int t, n;
    bool *unused;
    int *ans;
    cin >> t;
    do
    {
        input(n, ans, unused);
        Try(n, ans, unused, 0);
        cout << '\n'; // dsa02034 thi` bo? dong` nay`
        delete[] unused, ans;

    } while (--t);
    return 0;
}