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
void HanoiTower(int n, char st, char en, char tg)
{
    if (n == 1)
        cout << st << " -> " << en << '\n';
    else
    {
        HanoiTower(n - 1, st, tg, en);
        cout << st << " -> " << en << '\n';
        HanoiTower(n - 1, tg, en, st);
    }
}
void __vippro__()
{
    int n;
    cin >> n;
    HanoiTower(n, 'A', 'C', 'B');
}

__ducsjukap__()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // int T;
    // cin >> T;
    // dr(T, T, 0)
    __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro