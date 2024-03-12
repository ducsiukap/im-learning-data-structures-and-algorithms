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
#define fd(i, a, b) for (i = a; i < b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

void Reverse(vector<int> &v, int &n)
{
    int i, j;
    i = 0;
    j = n - 1;
    while (i < j)
    {
        swap(v[i], v[j]);
        ++i;
        --j;
    }
}

void __vippro__()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int i;
    fr(i, 0, n) cin >> v[i];
    Reverse(v, n);
    fr(i, 0, n) cout << v[i] << ' ';
    cout << '\n';
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