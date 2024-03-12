#include <iostream>
using namespace std;

void show(int *a, int &n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << '\n';
}

void genNext(int *a, int &n, int &k)
{
    if (a[0] == n - k + 1)
    {
        for (int i = 1; i <= k; ++i)
            cout << i << ' ';
        cout << '\n';
        return;
    }
    int i = k - 1;
    while (i >= 0 && a[i] == n - k + i + 1)
        --i;
    ++a[i];
    while (++i < k)
        a[i] = a[i - 1] + 1;
    show(a, k);
}

int main()
{
    int *a, n, k, t;
    cin >> t;
    while (t)
    {
        --t;
        cin >> n >> k;
        a = new int[k];
        int i;
        for (int i = 0; i < k; ++i)
            cin >> a[i];
        genNext(a, n, k);
        delete[] a;
    }
    system("pause");
    return 0;
}