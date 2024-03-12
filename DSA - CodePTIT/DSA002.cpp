#include <iostream>
using namespace std;

bool sinh(bool *a, int &n)
{
    int i = n - 1;
    while (i >= 0 && a[i])
    {
        a[i] = 0;
        --i;
    }
    if (i == -1)
        return false;
    a[i] = 1;
    return true;
}

void show(int *a, bool *b, int &n)
{
    for (int i = 0; i < n; ++i)
        if (b[i])
            cout << a[i] << ' ';
    cout << '\n';
}

bool tinhtong(int *a, bool *b, int &n, int &k)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += a[i] * b[i];
        if (sum > k)
            return false;
    }
    return sum == k;
}

int main()
{
    int n, k, i;
    cin >> n >> k;
    int *a = new int[n];
    bool *b = new bool[n];
    for (i = 0; i < n; ++i)
    {
        cin >> a[i];
        b[i] = 0;
    }
    int dem = 0;
    while (sinh(b, n))
    {
        if (tinhtong(a, b, n, k))
        {
            show(a, b, n);
            ++dem;
        }
    }
    cout << dem << '\n';
    system("pause");
    return 0;
}