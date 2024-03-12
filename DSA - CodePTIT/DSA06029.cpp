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

void __vippro__()
{
    int n, i, j, key;
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> res;

    fr(i, 0, n) cin >> v[i];
    fr(i, 0, n)
    {
        key = v[i];
        dd(j, i - 1, 0)
        {
            if (v[j] > key)
                swap(v[j], v[j + 1]);
            else
                break;
        }
        vector<int> tmp;
        fd(j, 0, i) tmp.push_back(v[j]);
        res.push_back(tmp);
    }
    n = res.size();
    while (--n >= 0)
    {
        cout << "Buoc " << n << ':';
        for (int &x : res[n])
            cout << ' ' << x;
        cout << '\n';
    }
}

__ducsjukap__()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    // cin >> T;
    dr(T, 1, 0)
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro