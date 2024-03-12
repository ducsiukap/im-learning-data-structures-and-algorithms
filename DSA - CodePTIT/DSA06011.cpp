#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void __vippro__()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    int ans = 2e6, tmp;
    int i = 0, j = n - 1;
    while (i < j)
    {
        tmp = v[i] + v[j];
        if (tmp == 0)
        {
            ans = tmp;
            break;
        }
        if (abs(tmp) < abs(ans) || (abs(tmp) == abs(ans) && tmp < ans))
            ans = tmp;
        if (tmp < 0)
            ++i;
        else
            --j;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        __vippro__();
    return 0;
}