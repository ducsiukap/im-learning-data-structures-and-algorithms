//* Bucket Sort Algorithm
// same idea with Counting Sort Algorithm
/*
- chia cac phan tu cua mang cho cung 1 so sao cho  0 <= a[i] < 1
- phan vung cac nhom theo so thap nhan thu nhat
- sort lan luot cac nhom
=> merge cac nhom lai => output
vd:
a = {0.143, 0.003, 0.276, 0.11, 0.331, 0.971}
=>                                     =>   sort:
    b[0] = 0.003                            b[0] = 0.003
    b[1] = 0.143 -> 0.11                    b[1] = 0.11 -> 0.143
    b[2] = 0.276                            ....
    b[3] = 0.331
    ...
    b[9] = 0.971                            b[9] = 0.971

=>merge:
-> sorted array (output) : a = {0.003, 0.11, 0.143, 0.276, 0.331, 0.971}
*/
#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int> &b) // sort cac nhom sau khi phan chia
{
    int len = b.size();
    int key, i, j;
    for (i = 1; i < len; ++i)
    {
        key = b[i];
        for (j = i - 1; j > -1; --j)
            if (b[j] > key)
                swap(b[j], b[j + 1]);
        b[j + 1] = key;
    }
}

void bucket_sort(int *a, const int &low, const int &high)
{
    int max_element = a[low]; // [phan tu lon nhat cua mang? a]
    // a[i] / max_element <= 1 (i = 0, 1, ..., high - 1)
    int i;
    // find max_element of a
    for (i = low + 1; i < high; ++i)
        if (a[i] > max_element)
            max_element = a[i];

    vector<vector<int>> b(11); // vector phan chia nhom cac phan tu trong mang a
    // 0.1 -> 1.0
    for (i = low; i < high; ++i)
        // a[i] = 0.1.. -> b[1] = b[a[i] * 10]
        b[a[i] * 10 / max_element].push_back(a[i]);

    // sort tung nhom cua mang? b
    // b[10] chi co 1 phan tu hoac cac phan tu bang nha => khong can sort
    for (i = 0; i < 10; ++i)
        insertion_sort(b[i]);

    // merge cac nhom
    int nowPos = low; // current considered position in array a (output)
    for (i = 0; i <= 10; ++i)
        for (int x : b[i]) // gan lan luot cac phan tu tu be den lon vao output array
        {
            a[nowPos] = x;
            ++nowPos;
        }
}

void print_array(int *a, const int &array_size)
{
    for (int i = 0; i < array_size; ++i)
        cout << a[i] << ' ';
    cout << '\n';
}

int main()
{
    int a[] = {9, 3, 5, 3, 1, 0, 7, 3, 4, 6, 8, 0}; // base array, 12 elements
    // after sorting: 0 0 1 3 3 3 4 5 6 7 8 9
    int array_size = sizeof(a) / sizeof(a[0]); // array size
    cout << "unsorted array : ";
    print_array(a, array_size);
    cout << '\n';

    // call bucket_sort(array[], begin, end)
    bucket_sort(a, 0, array_size);
    // after sorting: 0 0 1 3 3 3 4 5 6 7 8 9

    cout << "sorted array   : ";
    print_array(a, array_size);

    cin.get(); // pause console
    return 0;
}