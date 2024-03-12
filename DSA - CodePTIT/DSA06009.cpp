// * Code by Ducsjukapvippro
// * dont cry bae =))
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i <= b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (int i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;
void max_heapify(vector<int> &v, int &vector_size, int current_node)
{
    int largest = current_node, child = 2 * current_node + 1;
    if (child < vector_size)
    {
        if (v[child] > v[largest])
            largest = child;
        ++child;
        if (child < vector_size && v[child] > v[largest])
            largest = child;
        if (largest != current_node)
        {
            swap(v[current_node], v[largest]);
            max_heapify(v, vector_size, largest);
        }
    }
}
void build_max_heap(vector<int> &v, int &vector_size)
{
    dd(i, vector_size / 2 - 1, 0) max_heapify(v, vector_size, i);
}
void heapsort(vector<int> &v, int vector_size)
{
    build_max_heap(v, vector_size);
    while (--vector_size)
    {
        swap(v[0], v[vector_size]);
        max_heapify(v, vector_size, 0);
    }
}

ll sumK(vector<int> &v, int &vector_size, int &K)
{
    ll ans = 0;
    int i, mid, tmp, j;
    --vector_size;
    fr(i, 0, vector_size)
    {
        mid = (i + 1 + vector_size) / 2;
        tmp = v[i] + v[mid];
        if (tmp == K)
        {
            ++ans;
            j = mid - 1;
            while (j > i && v[j] == v[mid])
            {
                ++ans;
                --j;
            }
            j = mid + 1;
            while (j <= vector_size && v[j] == v[mid])
            {
                ++ans;
                ++j;
            }
        }
        else if (tmp > K)
        {
            dr(j, mid - 1, i)
            {
                tmp = v[j] + v[i];
                if (tmp == K)
                    ++ans;
                else if (tmp < K)
                    break;
            }
        }
        else
        {
            fd(j, mid + 1, vector_size)
            {
                tmp = v[j] + v[i];
                if (tmp == K)
                    ++ans;
                else if (tmp > K)
                    break;
            }
        }
    }
    return ans;
}
void __vippro__()
{
    int vector_size, K;
    vector<int> v;
    cin >> vector_size >> K;
    v.resize(vector_size);
    for (int &element : v)
        cin >> element;
    heapsort(v, vector_size);
    cout << sumK(v, vector_size, K) << '\n';
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