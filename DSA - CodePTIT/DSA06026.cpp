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
    fr(i, 0, n) cin >> v[i];
    bool ok;
    fr(i, 1, n)
    {
        ok = 1;
        fr(j, 0, n - i) if (v[j] > v[j + 1])
        {
            swap(v[j], v[j + 1]);
            ok = 0;
        }
        if (ok)
            break;
        cout << "Buoc " << i << ':';
        fr(j, 0, n) cout << ' ' << v[j];
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