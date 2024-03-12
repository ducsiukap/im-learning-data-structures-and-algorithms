#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int interpolationSearch(vector<int> &v, int low, int high, int x)
{
    int pos, mid;
    pos = -1;
    while (low <= high && x >= v[low] && x <= v[high])
    {
        if (v[high] == v[low]) // tránh trường hợp mảng có các phần tử giống nhau
        {
            if (v[low] == x)
                pos = low;
            break;
        }
        mid = low + (((double)high - low) / (v[high] - v[low])) * (x - v[low]);
        cout << mid << ' ';
        if (v[mid] == x)
            pos = x;

        if (x <= v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return pos;
}

int Count(vector<int> &v, int &st, int en, int x)
{
    int res, pos;
    res = 1;
    pos = st;
    while (1)
    {
        pos = interpolationSearch(v, pos + 1, en, x);
        if (pos == -1)
            break;
        else
            ++res;
    }
    cout << "\ncnt = ";
    st += res;
    return res;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        sort(v.begin(), v.end());

        for (int i = 0; i < n; ++i)
            cout << v[i] << ' ';
        cout << '\n';
        bool ok = 0;
        cout << interpolationSearch(v, 0, n - 1, 4) << '\n';
        // for (int i = 0; i < n;)
        // {
        //     cout << v[i] << " : " << Count(v, i, n - 1, v[i]) << '\n';
        //     // if (Count(v, i, n - 1, v[i]) > n / 2)
        //     // {
        //     //     cout << v[i] << '\n';
        //     //     ok = 1;
        //     //     break;
        //     // }
        // }
        if (!ok)
            cout << "NO\n";
    }
    return 0;
}