// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i <= b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

int twoStack(vector<ll> &v1, vector<ll> &v2, int &n1, int &n2, int &maxSum)
{
    int mx = 0, j = n2;
    for (int i = 0; i <= n1; ++i)
    {
        if (v1[i] > maxSum)
            break;
        while (j >= 0)
        {
            if (v1[i] + v2[j] <= maxSum)
                break;
            --j;
        }
        mx = max(mx, i + j);
    }
    return mx;
}

void __vippro__()
{
    int n1, n2, maxSum;
    cin >> n1 >> n2 >> maxSum;
    vector<ll> v1(n1 + 1), v2(n2 + 1);
    v1[0] = v2[0] = 0;
    int i;
    fd(i, 1, n1)
    {
        cin >> v1[i];
        v1[i] += v1[i - 1];
    }
    fd(i, 1, n2)
    {
        cin >> v2[i];
        v2[i] += v2[i - 1];
    }
    cout << twoStack(v1, v2, n1, n2, maxSum) << '\n';
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