#include <cstdio>

#define INF 1000000000

int f[80000][20], a[20][20], n;

int min(int a, int b)
{
    return a < b ? a : b;
}

int F(int mask, int end)
{
    if (mask == 0)
        return 0;
    int &res = f[mask][end];
    if (res == 0)
    {
        res = INF;
        for (int i = 0; i < n; ++i)
            if (mask & (1 << i))
                res = min(res, F(mask & ~(1 << i), i) + a[i][end]);
    }
    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        for (int i = 0; i < 80000; ++i)
            for (int j = 0; j < 20; ++j)
                f[i][j] = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &a[i][j]);
        int res = INF;
        for (int i = 0; i < n; ++i)
            res = min(res, F((1 << n) - 1, i));
        printf("%d\n", res);
    }
    return 0;
}
