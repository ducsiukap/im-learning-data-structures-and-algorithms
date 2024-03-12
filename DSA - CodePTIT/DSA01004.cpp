#include <iostream>
using namespace std;

bool sinh(int *a, int &n, int &k)
{
    int i = k - 1;
    while (i >= 0 && a[i] == n - k + i + 1)
        --i;
    if (i == -1)
        return false;
    ++a[i];
    while (++i < k)
        a[i] = a[i - 1] + 1;
    return true;
}

void show(int *a, int &k)
{
    for (int i = 0; i < k; ++i)
        cout << a[i];
    cout << ' ';
}

int main()
{
    int t, n, k, *a;
    cin >> t;
    while (t)
    {
        --t;
        cin >> n >> k;
        a = new int[k];
        for (int i = 0; i < k; ++i)
            a[i] = i + 1;
        show(a, k);
        while (sinh(a, n, k))
            show(a, k);
        delete[] a;
        cout << '\n';
    }
    return 0;
}