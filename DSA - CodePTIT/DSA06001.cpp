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

void maxheapify(vector<int> &v, int &n, int i)
{
    int largest = i, j = 2 * i;
    if (j < n)
    {
        if (v[j] > v[i])
            largest = j;
        ++j;
        if (j < n && v[j] > v[largest])
            largest = j;
        if (largest != i)
        {
            swap(v[i], v[largest]);
            maxheapify(v, n, largest);
        }
    }
}
void buildmaxheap(vector<int> &v, int &n)
{
    for (int i = n / 2 - 1; i >= 0; --i)
        maxheapify(v, n, i);
}
void heapsort(vector<int> &v, int n)
{
    buildmaxheap(v, n);
    while (--n)
    {
        swap(v[0], v[n]);
        maxheapify(v, n, 0);
    }
}

void __vippro__()
{
    int n, i;
    cin >> n;
    vector<int> v(n);
    fr(i, 0, n) cin >> v[i];
    heapsort(v, n);
    i = 0;
    --n;
    while (i < n)
    {
        cout << v[n] << ' ' << v[i] << ' ';
        ++i;
        --n;
    }
    if (i == n)
        cout << v[i];
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