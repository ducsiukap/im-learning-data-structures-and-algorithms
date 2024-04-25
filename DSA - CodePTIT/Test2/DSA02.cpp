#include <bits/stdc++.h>
using namespace std;

long long countNonDecreasing(int n)
{
    long long dp[10][n + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i < 10; i++)
        dp[i][1] = 1;

    for (int digit = 0; digit <= 9; digit++)
    {
        for (int len = 2; len <= n; len++)
        {
            for (int x = 0; x <= digit; x++)
                dp[digit][len] += dp[x][len - 1];
        }
    }

    long long count = 0;
    for (int i = 0; i < 10; i++)
    {
        count += dp[i][n];
        count %= int(1e9 + 7);
    }

    return count;
}

int main()
{
    int n = 100;
    cout << countNonDecreasing(n);
    return 0;
}
