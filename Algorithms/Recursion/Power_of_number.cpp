// Find the value of a number raised to its reverse

//  * Code by Ducsjukapvippro
//  * dont cry bae =))
//  * neu ngay mai khong den thi sao?

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

#define MOD int(1e9 + 7)

ll PowerOfNumber(int Number, int power)
{
    if (Number == 0 || Number == 1) // 0^x = 0, 1^x = 1
        return Number;

    if (power == 1) // base case
        return Number;

    return (Number * PowerOfNumber(Number, power - 1)) % MOD;
}

int Reverse(int Number)
{
    int rev = 0;
    while (Number)
    {
        rev = rev * 10 + Number % 10;
        Number /= 10;
    }
    return rev;
}
void __vippro__()
{
    int number, power;
    cout << "Enter number : ";
    cin >> number;

    power = Reverse(number);

    cout << "\n------------------\n";
    cout << "pow(" << number << ", " << power << ") = " << PowerOfNumber(number, power) << '\n';
    cout << "------------------\n";
}

__ducsjukap__
{
    // faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
