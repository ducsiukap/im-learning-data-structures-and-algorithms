// * Code by Ducsjukapvippro
// * dont cry bae =))
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

void max_heapify(vector<int> &v, int &n, int pos)
{
    int i = pos, j = 2 * pos + 1;
    if (j < n)
    {
        if (v[j] > v[i])
            i = j;
        ++j;
        if (j < n && v[j] > v[i])
            i = j;
        if (i != pos)
        {
            swap(v[pos], v[i]);
            max_heapify(v, n, i);
        }
    }
}
void build_max_heap(vector<int> &v, int &n)
{
    int i;
    dd(i, n / 2 - 1, 0) max_heapify(v, n, i);
}
void heapsort(vector<int> &v, int n)
{
    build_max_heap(v, n);
    while (--n)
    {
        swap(v[n], v[0]);
        max_heapify(v, n, 0);
    }
}

void __vippro__()
{
    int n, i;
    cin >> n;
    vector<int> v(n);
    fr(i, 0, n) cin >> v[i];
    heapsort(v, n);
    fr(i, 0, n) cout << v[i] << ' ';
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
