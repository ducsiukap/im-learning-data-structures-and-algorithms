#include <iostream>
using namespace std;

int check(int *a, int &n)
{
    int dem = 0;
    for (int i = 0; i <= n; ++i)
        dem += a[i];
    return dem;
}

void show(int *a, int &n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i];
    cout << '\n';
}

void Try(int *a, int &n, int &k, int i)
{
    int dem;
    for (int j = 0; j <= 1; ++j)
    {
        a[i] = j;
        dem = check(a, i);
        if (i == n - 1)
        {
            if (dem == k)
                show(a, n);
        }
        else if (dem <= k && k - dem <= n - i - 1)
            Try(a, n, k, i + 1);
    }
}

int main()
{
    int t, n, k;
    int *a;
    cin >> t;
    while (t)
    {
        --t;
        cin >> n >> k;
        a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = 0;
        Try(a, n, k, 0);
        delete[] a;
    }
    return 0;
}