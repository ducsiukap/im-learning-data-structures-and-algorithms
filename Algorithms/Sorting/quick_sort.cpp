//* Quick Sort Algorithm
// using Devide and Conquer technique
#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

// partition(A, low, high) -> find mid point
// using an element as  a pivot to compair
// partition the array to 2 subarrays
// left subarray is all of element which is not bigger than pivot
// right subarray is the rest of base array
// this function will return the mid point posiition
// int partition(int *a, const int &low, const int &high)
// {
//     int pivot = a[high]; // use the last element as the pivot element
//     int i = low;         // separating position of 2 subaaray
//     int j = low;
//     while (j < high) // iterate over elements
//     {
//         if (a[j] < pivot) // if a[j] is left subarray's member
//         {
//             swap(a[i], a[j]); // move to left subarray
//             ++i;              // position of pivod
//         }
//         ++j; // consider the next element
//     }
//     // now i is the pivot position
//     // and the mid point of array
//     swap(a[i], a[high]);
//     return i; // return mid point
// }

// // quick_sort function
// // partition the array to two subarray
// // and sort each of them
// void quick_sort(int *a, const int &low, const int &high)
// {
//     if (low < high)
//     {
//         int mid = partition(a, low, high); // take the midpoint

//         quick_sort(a, low, mid - 1);  // sort left subarray
//         quick_sort(a, mid + 1, high); // sort right subarray
//     }
// }

// // show current array
// void print_array(int *a, const int &n)
// {
//     for (int i = 0; i <= n; ++i)
//         cout << a[i] << ' ';
//     cout << '\n';
// }

// int main()
// {
//     int a[] = {1, -4, 3, 2, 5, 0, -7, 6, 3}; // base array, 9 elements
//     // after sorting: -7 -4 0 1 2 3 3 5 6
//     cout << "unsorted array : ";
//     print_array(a, 8);

//     quick_sort(a, 0, 8); // call quicksort

//     cout << "sorted array   : ";
//     print_array(a, 8);

//     cin.get(); // pause console
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int Randomized_partition(vector<int> &v, int &low, int &high)
{
    srand(time(0));
    int rand_pos = rand() % (high - low + 1) + low; // get random position in[low, high]
    swap(v[rand_pos], v[high]);                     // lay 1 phan tu bat ky lam pivot

    int pivot = v[high]; // set pivot
    int left = low, right = high - 1;
    while (left < right)
    {
        while (left <= right && v[left] <= pivot)
            ++left;
        while (left <= right && v[right] >= pivot)
            --right;
        if (left < right)
        {
            swap(v[left], v[right]);
            ++left;
            --right;
        }
    }
    swap(v[left], v[high]);
    return left;
}

void sort_function(vector<int> &v, int low, int high) // randomized quick_sort
{
    if (low < high)
    {
        int p = Randomized_partition(v, low, high);
        sort_function(v, low, p - 1);  // sort left sub array
        sort_function(v, p + 1, high); // sort right sub array
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