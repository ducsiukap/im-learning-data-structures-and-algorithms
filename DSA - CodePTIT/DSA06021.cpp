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

int findPosOfMinimum(vector<int> &v, int low, int high, int &n)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (v[mid] < v[n - 1])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return mid;
}

int Binary_search(vector<int> &v, int low, int high, int &k)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (v[mid] == k)
            return mid + 1;
        if (v[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void __vippro__()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    int Min = findPosOfMinimum(v, 0, n - 1, n);
    if (Min)
    {
        if (k == v[n - 1])
            cout << n;
        else if (k < v[n - 1])
            cout << Binary_search(v, Min, n - 1, k);
        else
            cout << Binary_search(v, 0, Min - 1, k);
    }
    else
        cout << Binary_search(v, 0, n - 1, k);
    cout << '\n';
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