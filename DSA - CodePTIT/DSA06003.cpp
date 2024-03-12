// * Code by Ducsjukapvippro
// * dont cry bae =))
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i < b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

void __vippro__()
{
    int n, i, j, pivot, ans;
    cin >> n;
    vector<int> v(n);
    fr(i, 0, n) cin >> v[i];
    ans = 0;
    fr(i, 0, n)
    {
        pivot = i;
        fr(j, i + 1, n) if (v[j] < v[pivot]) pivot = j;
        if (pivot != i)
        {
            swap(v[i], v[pivot]);
            ++ans;
        }
    }
    cout << ans << '\n';
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