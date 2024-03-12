#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
void input(multiset<ll> &ms)
{
    int n, x;
    cin >> n;
    do
    {
        cin >> x;
        ms.insert(x);
    } while (--n);
}
void output(multiset<ll> &ms)
{
    ll res = 0, tmp;
    while (ms.size() > 1)
    {
        tmp = *ms.begin();
        ms.erase(ms.begin());
        tmp += *ms.begin();
        ms.erase(ms.begin());
        ms.insert(tmp);
        res += tmp;
    }
    cout << res << '\n';
    ms.clear();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    multiset<ll> ms;
    cin >> t;
    do
    {
        input(ms);
        output(ms);
    } while (--t);
    return 0;
}