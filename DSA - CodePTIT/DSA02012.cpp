#include <iostream>
#include <vector>
using namespace std;

void input(int &row, int &col, int &ans)
{
    cin >> row >> col;
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            cin >> ans;
    ans = 0;
    --row;
    --col;
}

void Try(int &ans, int &row, int &col, int r, int c)
{
    if (r == row && c == col)
        ++ans;
    else
    {
        if (r < row)
            Try(ans, row, col, r + 1, c);
        if (c < col)
            Try(ans, row, col, r, c + 1);
    }
}

void output(int &ans)
{
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, m, n, ans;
    cin >> t;
    do
    {
        input(m, n, ans);
        Try(ans, m, n, 0, 0);
        cout << ans << '\n';
    } while (--t);
    return 0;
}