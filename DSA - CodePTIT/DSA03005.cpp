#include <iostream>
#include <math.h>
using namespace std;

void max_heapify(int *a, int &n, int i)
{
    int largest = i, j = 2 * i + 1;
    if (j < n)
    {
        if (a[j] > a[i])
            largest = j;
        ++j;
        if (j < n && a[j] > a[largest])
            largest = j;
        if (largest != i)
        {
            swap(a[i], a[largest]);
            max_heapify(a, n, largest);
        }
    }
}
void build_max_heap(int *a, int &n)
{
    for (int i = n / 2 - 1; i >= 0; --i)
        max_heapify(a, n, i);
}
void heap_sort(int *a, int n)
{
    build_max_heap(a, n);
    for (int i = n - 1; i >= 0; --i)
    {
        swap(a[i], a[0]);
        --n;
        max_heapify(a, n, 0);
    }
}
void input(int &n, int &k, int *&a)
{
    cin >> n >> k;
    if (k > n - k)
        k = n - k;
    a = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    heap_sort(a, n);
}
void output(int *&a, int &n, int &k)
{
    int i, res;
    i = res = 0;
    while (i < k)
    {
        res -= a[i];
        ++i;
    }
    while (i < n)
    {
        res += a[i];
        ++i;
    }
    cout << res << '\n';
    delete[] a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, k, *a;
    cin >> t;
    do
    {
        input(n, k, a);
        output(a, n, k);
    } while (--t);
    return 0;
}