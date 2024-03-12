// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (int i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i <= b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

bool isOk(vector<int> &v, int i, int j)
{
    fr(x, 0, i) if (v[x] == j || abs(x - i) == abs(j - v[x])) return false;
    return true;
}

void Try(vector<int> &v, int i, int &n, int &ans)
{
    fr(j, 0, n)
    {
        if (isOk(v, i, j))
        {
            v[i] = j;
            if (i == n - 1)
                ++ans;
            else
                Try(v, i + 1, n, ans);
        }
    }
}

void __vippro__()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int ans = 0;
    Try(v, 0, n, ans);
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