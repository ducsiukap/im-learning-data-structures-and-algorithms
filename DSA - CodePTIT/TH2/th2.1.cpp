// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define code_no_bug() int main()
#define fr(i, a, b) for (int i = a; i < b; ++i)
#define fd(i, a, b) for (int i = a; i <= b; ++i)
#define dr(i, a, b) for (int i = a; i > b; --i)
#define dd(i, a, b) for (int i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()

void Try(vi &v, int &n, bool &flag, ll &totalSum, ll currentSum, int i)
{
    if (flag || currentSum > totalSum)
        return;

    if (currentSum == totalSum)
        flag = true;

    else
        fr(j, i, n) Try(v, n, flag, totalSum, currentSum + v[j], j + 1);
}

void __ducsjkap_vippro__()
{
    int n;
    cin >> n;

    vi v(n);
    fr(i, 0, n) cin >> v[i];

    ll totalSum = 0;
    fr(i, 0, n) totalSum += v[i];

    if (totalSum & 1)
        cout << "NO" << '\n';
    else
    {
        totalSum >>= 1;
        bool has_sub_arr = false;
        Try(v, n, has_sub_arr, totalSum, 0, 0);

        cout << (has_sub_arr ? "YES" : "NO") << '\n';
    }
}

code_no_bug()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T)
    {
        --T;
        __ducsjkap_vippro__();
    }

    return 0;
}
// * Code by Ducsjukapvippro