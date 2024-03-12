/*
Sap xep giam dan:
Duyet tu vi tri thu 2 -> vi tri cuoi cung, o moi lan duyet:
    +tim vi tri phan tu dau tien tu vi tri  i - 1 nho hon ptu hien tai
    +chen phan tu hien tai vao sau vi tri vua tim duoc
//* pseudocode:
for i = 2 to A.length
    key = a[i]
    j = i - 1
    while(j && a[j] > key)
        a[j + 1] = a[j]
        --j;
    a[j + 1] = key
*/
#include <iostream>
#include <vector>
using namespace std;

void sort_function(vector<int> &v, int low, int high) // insertion_sort
{
    int pivot;
    for (int i = low + 1; i <= high; ++i)
    {
        pivot = v[i];
        for (int j = i - 1; j >= low; --j)
            if (v[j] > pivot)
                swap(v[j], v[j + 1]);
            else
                break;
    }
}

void show_array(vector<int> &v, int len)
{
    for (int i = 0; i < len; ++i)
        cout << v[i] << ' ';
    cout << '\n';
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    sort_function(v, 0, n - 1); // call sort_function
    show_array(v, n);           // show sorted array
    return 0;
}