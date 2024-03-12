#include <iostream>
using namespace std;

bool gen(int *a, int &n, int &k)
{
    int i = k;
    while (i && a[i] == a[i - 1] + 1)
        --i;
    if (!i)
        return false;
    --a[i];
    for (int j = k; j > i; --j)
        a[j] = n - k + j;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, *a, n, k, ans;
    cin >> t;
    while (t)
    {
        --t;
        cin >> n >> k;
        a = new int[k + 1];
        for (int i = 1; i <= k; ++i)
            cin >> a[i];
        a[0] = 0;
        ans = 1;
        while (gen(a, n, k))
            ++ans;
        cout << ans << '\n';
        delete[] a;
    }
    return 0;
}