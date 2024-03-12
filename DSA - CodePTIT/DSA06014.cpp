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
int a[1000001];
void initPrimeArray()
{
    for (int i = 0; i < 1000001; ++i)
        a[i] = 1;
    a[0] = a[1] = 0;
    for (int i = 2; i < 1001; ++i)
    {
        if (a[i])
            for (int j = i * i; j < 1000001; j += i)
                a[j] = 0;
    }
}

void __vippro__()
{
    int k, ok;
    cin >> k;
    int i = 2;
    ok = 0;
    while (i <= k / 2)
    {
        if (a[i] && a[k - i])
        {
            cout << i << ' ' << k - i << '\n';
            ok = 1;
            break;
        }
        ++i;
    }
    if (!ok)
        cout << "-1\n";
}

__ducsjukap__()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    initPrimeArray();
    int T;
    cin >> T;
    dr(T, T, 0)
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro