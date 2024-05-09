// Given an array of n positive integers and a positive integer k,
// the task is to find the maximum subarray size
// such that all subarrays of that size
// have the sum of elements less than or equals to k.

// using prefix sum and binary search

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

int Bsearch(v(int) prefix, int n, int k)
{
    int ans = 0;

    int left = 0, right = n - 1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;

        int ok = 1;
        fr(i, mid, n)
        {
            if (prefix[i] - prefix[i - mid] > k)
            {
                ok = 0;
                break;
            }
        }

        if (ok)
        {
            left = mid + 1;
            ans = mid;
        }

        else
            right = mid - 1;
    }
    return ans;
}

int maxSize(v(int) a, int n, int k)
{
    v(int) prefix(n, 0);

    prefix[0] = a[0];
    fr(i, 1, n)
        prefix[i] = a[i] + prefix[i - 1];

    return Bsearch(prefix, n, k);
}

void maxSize_slidingWindows(v(int) a, int n, int k)
{
    int ans, start, sum;
    ans = n;
    start = sum = 0;

    fr(end, 0, n)
    {
        if (a[end] > k)
        {
            ans = 0;
            break;
        }

        sum += a[end];
        while (sum > k)
        {
            sum -= a[start];

            ans = min(ans, end - start);
            ++start;
        }
    }

    cout << "\n_____sliding window_____\n";
    if (ans)
        cout << "Max size: " << ans << '\n';
    else
        cout << "No have answer\n";
}

void __vippro__()
{
    int n, k;
    cin >> n >> k;
    v(int) a(n);
    in(a, n);

    cout << "_____prefix sum_____\n";
    int ans = maxSize(a, n, k);
    if (ans)
        cout << "Max size: " << ans << '\n';
    else
        cout << "No have answer!\n";

    maxSize_slidingWindows(a, n, k);
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
