// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i <= b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

int binary_search(vector<int> &v, int low, int high, int &value)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (v[mid] == value)
            return mid;

        if (v[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

void __vippro__()
{
    system("cls");
    int vector_size;

    cout << "size of vector = ";
    cin >> vector_size;
    vector<int> v(vector_size);
    cout << "enter element of vector:\n";
    for (int &i : v)
        cin >> i;

    int find_value;
    cout << "find : ";
    cin >> find_value;

    int pos = binary_search(v, 0, vector_size - 1, find_value);
    cout << "binary_search result : " << pos << "\n\n";
    system("pause");
}

__ducsjukap__()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    dr(T, T, 0)
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro