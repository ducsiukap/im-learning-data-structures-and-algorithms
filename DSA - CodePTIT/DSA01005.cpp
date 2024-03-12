#include <iostream>
using namespace std;

bool genNext(int *a, int &n)
{
    int i = n - 2;
    while (i >= 0 && a[i] > a[i + 1])
        --i;
    if (i == -1)
        return false;
    int j, k;
    j = i + 1;
    for (k = i + 2; k < n; ++k)
        if (a[k] > a[i] && a[k] < a[j])
            j = k;
    swap(a[i], a[j]);
    while (++i < --k)
        swap(a[i], a[k]);
    return true;
}

void show(int *a, int &n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i];
    cout << ' ';
}

int main()
{
    int t, n, *a;
    cin >> t;
    while (t)
    {
        --t;
        cin >> n;
        a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = i + 1;
        show(a, n);
        while (genNext(a, n))
            show(a, n);
        cout << '\n';
        delete[] a;
    }
    return 0;
}