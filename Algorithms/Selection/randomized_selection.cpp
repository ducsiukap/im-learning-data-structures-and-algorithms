//* Randomized Selection Algorithm
// Find ith smallest element in array
// like quicksort -> chia ra de tim phan tu do thuoc mang nao
#include <iostream>
#include <cstdlib>
using namespace std;

// use partition function like quicksort
int partition(int *a, const int &low, const int &high)
{
    int pivot = a[high];
    int i, j;
    i = j = low;
    while (j < high)
    {
        if (a[j] < pivot)
        {
            swap(a[j], a[i]);
            ++i;
        }
        ++j;
    }
    swap(a[i], a[high]);
    return i;
}
// randomized partition
int randomized_partition(int *a, const int &low, const int &high)
{
    int mid = (rand() % (high - low + 1)) + low;
    swap(a[mid], a[high]);
    return partition(a, low, high);
}

// randomized selection
int randomized_select(int *a, const int &low, const int &high, const int &ith)
{
    if (low == high)
        return a[low];
    int mid = randomized_partition(a, low, high);
    int k = mid - low + 1;
    if (k == ith)
        return a[mid];
    else if (k > ith)
        return randomized_select(a, low, mid - 1, ith);
    else
        return randomized_select(a, mid + 1, high, ith - mid + low - 1);
}

// print arrya
void print_array(int *a, const int &n)
{
    for (int i = 0; i <= n; ++i)
        cout << a[i] << ' ';
    cout << '\n';
}
int main()
{
    int a[] = {-2, 0, 5, 7, 4, 1, -8};
    int high = sizeof(a) / sizeof(a[0]) - 1;
    cout << "current array: ";
    print_array(a, high);
    // fint 4th smallest element of array
    cout << "4th smallest element in array is: " << randomized_select(a, 0, high, 4);
    cin.get();
    return 0;
}