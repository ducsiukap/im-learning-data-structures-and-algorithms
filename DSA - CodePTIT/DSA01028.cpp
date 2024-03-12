#include <iostream>
#include <set>
using namespace std;

void show(int *st, int *ans, int &k)
{
    for (int i = 1; i <= k; ++i)
        cout << st[ans[i]] << ' ';
    cout << '\n';
}

void Try(int *ans, int *st, int &n, int &k, const int &i)
{
    for (int j = ans[i - 1] + 1; j <= n - k + i - 1; ++j)
    {
        ans[i] = j;
        if (i == k)
            show(st, ans, k);
        else
            Try(ans, st, n, k, i + 1);
    }
}

int main()
{
    int n, k, x;
    int *ans, *st;
    set<int> s;
    cin >> n >> k;
    while (n)
    {
        --n;
        cin >> x;
        s.insert(x);
    }
    ans = new int[k + 1];
    ans[0] = -1;
    n = s.size();
    st = new int[n];
    x = 0;
    for (int i : s)
    {
        st[x] = i;
        ++x;
    }
    Try(ans, st, n, k, 1);
    return 0;
}