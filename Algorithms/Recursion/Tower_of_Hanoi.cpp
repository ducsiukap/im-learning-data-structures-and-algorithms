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

void Tower_of_Hanoi(int number_of_disk, char st, char en, char mid)
{
    if (number_of_disk == 1)
        cout << "mover disk from tower " << st << " to tower " << en << '\n ';
    else
    {
        Tower_of_Hanoi(number_of_disk - 1, st, mid, en);
        cout << "mover disk from tower " << st << " to tower " << en << '\n';
        Tower_of_Hanoi(number_of_disk - 1, mid, en, st);
    }
}

void __vippro__()
{
    int number_of_disk;
    cout << "Number of disk : ";
    cin >> number_of_disk;

    cout << "\n__________________\n";
    Tower_of_Hanoi(number_of_disk, 'A', 'C', 'B');
    cout << "__________________\n";
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
