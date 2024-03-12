#include <iostream>
using namespace std;

int solution(int *a, bool *u, int &n)
{
    int hs, i, j, ans, cnt;
    hs = 1;
    for (i = 2; i < n; ++i)
        hs *= i;
    ans = 0;
    for (i = 1; i < n; ++i)
    {
        cnt = 0;
        for (j = 1; j < a[i]; ++j)
            if (u[j])
                ++cnt;
        ans += cnt * hs;
        u[a[i]] = false;
        hs /= (n - i);
    }
    ++ans;
    return ans;
}

int main()
{
    int t, *a, n;
    bool *unused;
    cin >> t;
    while (t)
    {
        --t;
        cin >> n;
        a = new int[n + 1];
        unused = new bool[n + 1];
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            unused[i] = true;
        }
        cout << solution(a, unused, n) << '\n';
        delete[] a;
        delete[] unused;
    }
    return 0;
}