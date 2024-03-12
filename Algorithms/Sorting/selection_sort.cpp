#include <iostream>
#include <vector>
using namespace std;

void sort_function(vector<int> &v, int low, int high) // selection_sort
{
    int key;
    for (int i = low; i < high; ++i)
    {
        key = i;
        for (int j = i + 1; j <= high; ++j)
            if (v[j] < v[key])
                key = j;
        swap(v[i], v[key]);
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