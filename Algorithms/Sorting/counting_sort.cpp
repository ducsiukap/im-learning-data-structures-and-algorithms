//* Counting Sort Algorithm
// su dung mang? danh dau so lan xuat hien cua phan tu trong mang? ban dau
// sau do gan' lai vao mang sap xep

// Han che:
// phan tu co gia tri nho (khoang < 10^7)
// cac phan tu phai >= 0

#include <iostream>
using namespace std;

void counting_sort(int *unsorted_array, int *sorted_array, const int &array_size)
{
    int i;
    int max_element = -1; // find max element of array
    for (i = 0; i < array_size; ++i)
        if (unsorted_array[i] > max_element)
            max_element = unsorted_array[i];
    // element in range 0 to max_element
    // creat frequency marked array
    int *frequency = new int[max_element + 1];
    for (i = 0; i <= max_element; ++i)
        frequency[i] = 0; // ban dau tan suat cac phan tu la 0
    for (i = 0; i < array_size; ++i)
        ++frequency[unsorted_array[i]]; // increase frequency of a[i]

    // sorted
    int nowPos = 0; // now position in sorted array
    for (i = 0; i <= max_element; ++i)
        while (frequency[i])
        {
            sorted_array[nowPos] = i; // gan phan tu i vao sorted_array
            --frequency[i];           // duyet het phan tu i trong
            ++nowPos;                 // tang vi tri hien tai trong sorted_array
        }
}

// show array
void print_array(int *a, int len)
{
    for (int i = 0; i < len; ++i)
        cout << a[i] << ' ';
    cout << '\n';
}

int main()
{
    int a[] = {9, 3, 5, 3, 1, 0, 7, 3, 4, 6, 8, 0}; // base array, 12 elements
    // after sorting: 0 0 1 3 3 3 4 5 6 7 8 9
    int array_size = sizeof(a) / sizeof(a[0]); // array size
    int *sorted_array = new int[array_size];   // hold sorted outputs
    cout << "unsorted array : ";
    print_array(a, array_size);

    // call counting_sort(unsorted_array[], sorted_array[], array_size)
    counting_sort(a, sorted_array, array_size);
    // after sorting: 0 0 1 3 3 3 4 5 6 7 8 9

    cout << "sorted array   : ";
    print_array(sorted_array, array_size);

    cin.get(); // pause console
    return 0;
}