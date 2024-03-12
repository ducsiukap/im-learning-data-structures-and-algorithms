#include <iostream>
using namespace std;

int solution(int *a, int &n, int &k)
{
    int i = k;
    while (i && a[i] == n - k + i)
        --i;
    if (!i)
        return k;
    int dem = k - i + 1;
    a[i] += dem;
    for (int j = i + 1; j <= k; ++j)
    {
        if (a[j] <= a[i])
            --dem;
        else
            break;
    }
    return dem;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, *a, n, k;
    cin >> t;
    while (t)
    {
        --t;
        cin >> n >> k;
        a = new int[k + 1];
        for (int i = 1; i <= k; ++i)
            cin >> a[i];
        cout << solution(a, n, k) << '\n';
        delete[] a;
    }
    return 0;
}