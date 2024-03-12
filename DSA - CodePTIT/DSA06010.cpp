// * Code by Ducsjukapvippro
// * dont cry bae =))
// * Minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i < b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

void __vippro__()
{
    int n;
    string s;
    vector<bool> v(10, false);
    cin >> n;
    int i;
    do
    {
        cin >> s;
        fr(i, 0, s.size()) v[s[i] - '0'] = 1;
    } while (--n);
    fr(i, 0, 10) if (v[i]) cout << i << ' ';
    cout << '\n';
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