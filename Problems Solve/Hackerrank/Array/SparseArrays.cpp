// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (int i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i < b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

int findd(vector<string> &v, int &n, string &tmp)
{
    int ans = -1;
    fr(i, 0, n) if (v[i] == tmp)
    {
        ans = i;
        break;
    }
    return ans;
}

void __vippro__()
{
    int n, q, pos, ans;
    string tmp;
    cin >> n;
    vector<string> v(n);
    fr(i, 0, n) cin >> v[i];
    sort(v.begin(), v.end());
    cin >> q;
    while (q--)
    {
        cin >> tmp;
        pos = findd(v, n, tmp);
        if (pos == -1)
            cout << "0\n";
        else
        {
            ans = 1;
            fr(i, pos + 1, n) if (v[i] == tmp)++ ans;
            else break;
            cout << ans << '\n';
        }
    }
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
