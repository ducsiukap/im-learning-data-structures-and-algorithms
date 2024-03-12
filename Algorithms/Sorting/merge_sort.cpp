// //* Merge Sort (devide-conquer sort)
// /*
//  - step:
//     + partition the array to 2 subarray with the mid point = (begin + end) / 2
//     + recursive: call merge_sort() with each subarray to sort them
//     + merge: merge two sorted subarray
// */
// #include <iostream>
// using namespace std;

// // merge two sorted array become a sorted array
// void merge(int *a, const int &low, const int &high, const int &mid)
// {
//     int n1, n2;                          // size of each subarray
//     n1 = mid - low + 1;                  // a[low....mid]
//     n2 = high - mid;                     // a[mid + 1....high]
//     int *left_subarray, *right_subarray; // 2 sorted subarrays
//     left_subarray = new int[n1];
//     right_subarray = new int[n2];
//     int i, j; // iterate all elements of each subarray

//     // set left_subarray
//     for (i = 0; i < n1; ++i)
//         left_subarray[i] = a[low + i];
//     // set right_subarray
//     for (j = 0; j < n2; ++j)
//         right_subarray[j] = a[mid + j + 1];

//     // merge 2 subarray
//     i = j = 0;
//     int k = low; // index of main array
//     while (i < n1 && j < n2)
//     {
//         // a[k] = min(left[i], right[j])
//         if (left_subarray[i] < right_subarray[j])
//         {
//             a[k] = left_subarray[i];
//             ++i; // go to next element of left subarray
//         }
//         else
//         {
//             a[k] = right_subarray[j];
//             ++j; // go to next element of right subarray
//         }
//         ++k; // go to next element of main array
//     }
//     // lay phan con lai cua cac mang con
//     while (i < n1)
//     {
//         a[k] = left_subarray[i];
//         ++i;
//         ++k;
//     }
//     while (j < n2)
//     {
//         a[k] = right_subarray[j];
//         ++j;
//         ++k;
//     }
// }

// // merge_sort function
// void merge_sort(int *a, const int &low, const int &high)
// {
//     if (low < high)
//     {
//         // partition the array
//         int mid = (low + high) / 2; // mid point

//         // sorting all of subarray
//         merge_sort(a, low, mid);
//         merge_sort(a, mid + 1, high);

//         // merge two sorted subarrays:
//         merge(a, low, high, mid);
//     }
// }

// // print array
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

//     merge_sort(a, 0, 8); // call merge_sort

//     cout << "sorted array   : ";
//     print_array(a, 8);

//     cin.get(); // pause console
//     return 0;
// }
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &v, int &low, int &mid, int &high)
{
    int n1, n2; // size of 2 subarrays
    n1 = mid - low + 1;
    n2 = high - mid;
    vector<int> lsa(n1 + 1), rsa(n2 + 1); // left_subarray & right_subarray
    lsa[n1] = rsa[n2] = 2e9;
    int n1_itr, n2_itr;
    // set 2 subarrays
    for (n1_itr = 0; n1_itr < n1; ++n1_itr)
        lsa[n1_itr] = v[n1_itr + low];
    for (n2_itr = 0; n2_itr < n2; ++n2_itr)
        rsa[n2_itr] = v[n2_itr + mid + 1];
    // re-set array
    n1_itr = n2_itr = 0;
    int arr_itr = low;
    while (arr_itr <= high)
    {
        if (lsa[n1_itr] < rsa[n2_itr])
        {
            v[arr_itr] = lsa[n1_itr];
            ++n1_itr;
        }
        else
        {
            v[arr_itr] = rsa[n2_itr];
            ++n2_itr;
        }
        ++arr_itr;
    }
}

void sort_function(vector<int> &v, int low, int high) // bubble_sort
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        // partition v into 2 subarray
        sort_function(v, low, mid);
        sort_function(v, mid + 1, high);
        // merge 2 subarray
        merge(v, low, mid, high);
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