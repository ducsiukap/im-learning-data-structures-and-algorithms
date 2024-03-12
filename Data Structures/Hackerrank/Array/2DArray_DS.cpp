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
    vector<vector<int>> v(6, vector<int>(6));
    int i, j, sum;
    int mx = -63;
    fr(i, 0, 6) fr(j, 0, 6) cin >> v[i][j];
    fr(i, 0, 4) fr(j, 0, 4)
    {
        sum = v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j + 1] + v[i + 2][j] + v[i + 2][j + 1] + v[i + 2][j + 2];
        mx = max(mx, sum);
    }
    cout << mx << '\n';
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
