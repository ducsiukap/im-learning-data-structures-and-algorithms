#include <iostream>
#include <string>
using namespace std;
// sinh cau  hinh
bool sinh(int *a, int &n)
{
    int i = n / 2 - 1;
    while (i > -1 && a[i])
    {
        a[i] = 0;
        --i;
    }
    if (i == -1)
        return false;
    ++a[i];
    return true;
}
// in cau hinh
void show(int *a, int &n)
{
    int mid = n % 2;
    int i, j;
    for (i = 0; i <= mid; ++i)
    {
        for (j = 0; j < n / 2; ++j)
            cout << a[j] << ' ';
        if (mid)
            cout << i << ' ';
        while (--j >= 0)
            cout << a[j] << ' ';
        cout << '\n';
    }
}

int main()
{
    int n;
    int *a;
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; ++i)
        a[i] = 0;
    show(a, n);
    while (sinh(a, n))
        show(a, n);
    system("pause");
}