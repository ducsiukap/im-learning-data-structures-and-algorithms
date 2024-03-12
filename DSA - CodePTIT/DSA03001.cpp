#include <iostream>
using namespace std;
int main()
{
    int a[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
    int t, n, i, dem;
    cin >> t;
    do
    {
        cin >> n;
        i = 9;
        dem = 0;
        while (n)
        {
            dem += n / a[i];
            n %= a[i];
            --i;
        }
        cout << dem << '\n';
    } while (--t);
    return 0;
}