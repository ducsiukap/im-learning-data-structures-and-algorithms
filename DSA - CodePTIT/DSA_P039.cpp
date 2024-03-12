#include <bits/stdc++.h>
using namespace std;

int maxAssignment(vector<vector<int>> &a)
{
    int n = a.size();
    vector<vector<int>> dp(n + 1, vector<int>(1 << n, -1));
    dp[0][0] = 0;
    for (int mask = 0; mask < (1 << n); ++mask)
    {
        int i = __builtin_popcount(mask);
        for (int j = 0; j < n; ++j)
        {
            if ((mask >> j) & 1)
            {
                dp[i][mask] = max(dp[i][mask], dp[i - 1][mask ^ (1 << j)] + a[i - 1][j]);
            }
        }
    }
    return dp[n][(1 << n) - 1];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> a[i][j];
            }
        }
        cout << maxAssignment(a) << '\n';
    }
    return 0;
}
