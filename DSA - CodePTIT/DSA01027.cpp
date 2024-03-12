/*  Code by DucSiukapvippro */
//* dont cry bae =))

#include <iostream>

using namespace std;

#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);

void merge(int *a, const int &low, const int &high, int &mid)
{
    int n1, n2;
    int *a1, *a2;
    n1 = mid - low + 1;
    n2 = high - mid;
    a1 = new int[n1 + 1];
    a2 = new int[n2 + 1];
    int k;
    for (k = 0; k < n1; ++k)
        a1[k] = a[low + k];
    for (k = 0; k < n2; ++k)
        a2[k] = a[k + mid + 1];
    a1[n1] = a2[n2] = 1e9;
    n1 = n2 = 0;
    k = low;
    while (k <= high)
    {
        if (a1[n1] < a2[n2])
        {
            a[k] = a1[n1];
            ++n1;
        }
        else
        {
            a[k] = a2[n2];
            ++n2;
        }
        ++k;
    }
    delete[] a1;
    delete[] a2;
}

void merge_sort(int *a, const int &low, const int &high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        merge(a, low, high, mid);
    }
}

void show(int *ans, int *set, int &n)
{
    for (int i = 0; i <= n; ++i)
        cout << set[ans[i]] << ' ';
    cout << '\n';
}

void Try(int *set, int *ans, bool *unused, int &n, const int &i)
{
    for (int j = 0; j <= n; ++j)
    {
        if (unused[j])
        {
            ans[i] = j;
            unused[j] = false;
            if (i == n)
                show(ans, set, n);
            else
                Try(set, ans, unused, n, i + 1);
            unused[j] = true;
        }
    }
}

int main()
{
    // faster();
    int n;
    int *set, *ans;
    bool *unused;
    cin >> n;
    set = new int[n];
    ans = new int[n];
    unused = new bool[n];
    for (int i = 0; i < n; ++i)
    {
        unused[i] = true;
        cin >> set[i];
    }
    --n;
    merge_sort(set, 0, n);

    Try(set, ans, unused, n, 0);

    delete[] ans, set, unused;
    return 0;
}
/*  Code by DucSiukapvippro */