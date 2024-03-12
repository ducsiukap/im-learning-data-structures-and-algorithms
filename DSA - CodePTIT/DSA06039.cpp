// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i <= b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

int ternary_search(int a[], int low, int high, int &x)
{
    int mid1, mid2, pos;
    pos = -1;
    while (low <= high)
    {
        mid1 = low + (high - low) / 3;
        mid2 = low + 2 * (high - low) / 3;

        if (x > a[mid1])
        {
            low = mid1 + 1;
            if (x > a[mid2])
                low = mid2 + 1;
            else
                high = mid2 - 1;
        }
        else
            high = mid2 - 1;

        if (a[mid1] == x)
            pos = mid1;
        else if (a[mid2] == x)
            pos = mid2;
    }
    return pos;
}

void PreProcess(int *&a, int *&b, int &n)
{
    cin >> n;
    a = new int[n];
    b = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a + n);
}

void Search(int *&a, int *&b, int &n)
{
    int pos;
    for (int i = 0; i < n; ++i)
    {
        pos = ternary_search(a, 0, n - 1, b[i]);
        if (pos != n - 1)
            if (ternary_search(a, pos + 1, n - 1, b[i]) != -1)
            {
                cout << b[i] << '\n';
                return;
            }
    }
    cout << "NO\n";
    delete[] a, b;
}

void __vippro__()
{
    int n, *a, *b;
    PreProcess(a, b, n);
    Search(a, b, n);
}

__ducsjukap__()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    dr(T, T, 0)
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro