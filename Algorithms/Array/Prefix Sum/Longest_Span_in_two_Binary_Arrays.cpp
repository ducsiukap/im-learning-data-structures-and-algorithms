// Longest Span in two Binary Arrays
// sum(B1[i ... j]) == sum(B2[i ..... j])

// * Code by Ducsjukapvippro
// * dont cry bae =))
// * neu ngay mai khong den thi sao?

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

#define __ducsjukap__ int main()
#define faster()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define run() \
    int T;    \
    cin >> T; \
    while (T--)
#define v(x) vector<x>
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define fi first
#define se second
#define pb(a) push_back(a)
#define fr(i, a, b) for (int i = a; i < b; ++i)
#define fe(i, a, b) for (int i = a; i <= b; ++i)
#define dr(i, a, b) for (int i = a; i > b; --i)
#define de(i, a, b) for (int i = a; i >= b; --i)
#define in(x, n) fr(i, 0, n) cin >> x[i]
#define out(x, n, sep) fr(i, 0, n) cout << x[i] << sep
#define reset(x, n, value) fr(i, 0, n) x[i] = value

int longestCommonSum(v(int) b1, v(int) b2, int n)
{
    vector<int> diff(2 * n + 1, -1);
    int diff_index, ans, sum1, sum2;
    ans = sum1 = sum2 = 0;
    fr(i, 0, n)
    {
        sum1 += b1[i];
        sum2 += b2[i];
        diff_index = sum1 - sum2 + n;

        if (diff_index == n)
            ans = i + 1;
        else if (diff[diff_index] != -1)
        {
            int distance = i - diff[diff_index];

            ans = max(ans, distance);
        }

        else
            diff[diff_index] = i;
    }
    return ans;
}

void __vippro__()
{
    int n;
    cin >> n;

    v(int) b1(n), b2(n);
    in(b1, n);
    in(b2, n);

    cout << longestCommonSum(b1, b2, n) << '\n';
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
