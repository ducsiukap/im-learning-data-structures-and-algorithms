#include <iostream>
using namespace std;

void sinh(int *a, int &n)
{
    if (a[0] == n)
    {
        for (int i = 1; i <= n; ++i)
            cout << i << ' ';
        cout << '\n';
        return;
    }
    int i = n - 2, j, k;
    while (i >= 0 && a[i] > a[i + 1])
        --i;
    j = i + 1;
    for (k = i + 2; k < n; ++k)
        if (a[k] > a[i] && a[k] < a[j])
            j = k;
    swap(a[i], a[j]);
    --k;
    ++i;
    while (i < k)
    {
        swap(a[i], a[k]);
        ++i;
        --k;
    }
    for (i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << '\n';
}
int main()
{
    int *a, t, n;
    cin >> t;
    while (t)
    {
        --t;
        cin >> n;
        a = new int[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sinh(a, n);
        delete[] a;
    }
    return 0;
}