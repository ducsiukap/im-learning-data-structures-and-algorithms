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

ll TripleSmallerThanK(vector<int> &v, int &n, int &k)
{
    sort(v.begin(), v.end());
    int st, en, i;
    ll tmp, ans;

    ans = 0;
    fr(i, 0, n - 2)
    {
        if (v[i] >= k)
            break;
        st = i + 1;
        en = n - 1;

		tmp = v[i];
		tmp += v[st] + v[en];
        while (st < en)
        {
            if (tmp < k)
            {
                ans += en - st;
                tmp -= v[st];
                ++st;
                tmp += v[st];
            }
            else
        	{
        		tmp -= v[en];
        		--en;
        		tmp += v[en];
			}
        }
    }
    return ans;
}

void __vippro__()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    cout << TripleSmallerThanK(v, n, k) << '\n';
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
