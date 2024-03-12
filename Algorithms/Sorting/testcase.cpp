#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    int n, i;
    cin >> n;
    srand(time(0));
    cout << n << '\n';
    for (i = 0; i < n; ++i)
        cout << rand() % 10000 << ' ';
    cout << i << '\n';
}