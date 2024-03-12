#include <iostream>
using namespace std;

void heapify(int *&a, int &n, int i)
{
    int largest, j;
    largest = i;
    j = 2 * i + 1;
    if (j < n)
    {
        if (a[j] >= a[i])
            largest = j;
        ++j;
        if (j < n && a[j] >= a[largest])
            largest = j;
    }
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void build_max_heap(int *&a, int &n)
{
    for (int j = n / 2 - 1; j >= 0; --j)
        heapify(a, n, j);
}

void heap_sort(int *&a, int n)
{
    build_max_heap(a, n);
    for (int i = n - 1; i; --i)
    {
        swap(a[i], a[0]);
        --n;
        heapify(a, n, 0);
    }
}
void input(int *&a, int &n)
{
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    heap_sort(a, n);
}
void output(int *&a, int &n)
{
    int mod = 1e9 + 7;
    long long res = 0;
    for (int i = 0; i < n; ++i)
    {
        res += a[i] * i;
        res %= mod;
    }
    cout << res << '\n';
    delete[] a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, *a, n;
    cin >> t;
    do
    {
        input(a, n);
        output(a, n); // print result and free memory
    } while (--t);
    return 0;
}