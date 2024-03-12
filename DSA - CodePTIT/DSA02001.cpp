#include <iostream>
using namespace std;

void show(int *a, int &n)
{
    cout << '[';
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << a[n] << "]\n";
}

void dayso1(int *a, int &n)
{
    show(a, n);
    if (n < 1)
        return;
    for (int j = 0; j < n; ++j)
        a[j] += a[j + 1];
    --n;
    dayso1(a, n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    int *a;
    cin >> t;
    while (t)
    {
        --t;
        cin >> n;
        a = new int[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        --n;
        dayso1(a, n);
        delete[] a;
    }
    return 0;
}