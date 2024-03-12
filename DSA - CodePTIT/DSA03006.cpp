#include <iostream>
using namespace std;

void max_heapify(int a[], int &n, int i)
{
    int largest = i, child = 2 * i + 1;
    if (child < n)
    {
        if (a[child] > a[i])
            largest = child;
        ++child;
        if (child < n && a[child] > a[largest])
            largest = child;
        if (largest != i)
        {
            swap(a[largest], a[i]);
            max_heapify(a, n, largest);
        }
    }
}
void build_max_heap(int a[], int &n)
{
    int i = n / 2;
    while (--i >= 0)
        max_heapify(a, n, i);
}
void heapsort(int a[], int n)
{
    build_max_heap(a, n);
    while (--n)
    {
        swap(a[n], a[0]);
        max_heapify(a, n, 0);
    }
}
void input(int *&a, int *&b, int &n)
{
    cin >> n;
    a = new int[n];
    b = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    heapsort(b, n);
}
bool check(int a[], int b[], int &n)
{
    int i, j;
    i = 0;
    j = n - 1;
    while (i < j)
    {
        if (a[i] != b[i] && a[i] != b[j])
            return false;
        if (a[j] != b[j] && a[j] != b[i])
            return false;
        ++i;
        --j;
    }
    return true;
}
void output(int *&a, int *&b, int &n)
{
    if (check(a, b, n))
        cout << "Yes\n";
    else
        cout << "No\n";
    delete[] a, b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, *unsorted, *sorted;
    cin >> t;
    do
    {
        input(unsorted, sorted, n);
        output(unsorted, sorted, n);
    } while (--t);
    return 0;
}