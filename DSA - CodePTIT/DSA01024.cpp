#include <iostream>
using namespace std;

void merge(string *ds, const int &low, const int &high, const int &mid)
{
    int n1, n2;
    string *v1, *v2;
    n1 = mid - low + 1;
    n2 = high - mid;
    v1 = new string[n1 + 1];
    v2 = new string[n2 + 1];
    int i, j;
    for (i = 0; i < n1; ++i)
        v1[i] = ds[low + i];
    for (j = 0; j < n2; ++j)
        v2[j] = ds[mid + j + 1];
    v1[n1] = v2[n2] = "ZZZZZZZZZZZZZZZ";
    i = j = 0;
    for (n1 = low; n1 <= high; ++n1)
    {
        if (v1[i] < v2[j])
        {
            ds[n1] = v1[i];
            ++i;
        }
        else
        {
            ds[n1] = v2[j];
            ++j;
        }
    }
    delete[] v1;
    delete[] v2;
}

void merge_sort(string *ds, const int &low, const int &high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(ds, low, mid);
        merge_sort(ds, mid + 1, high);
        merge(ds, low, high, mid);
    }
}

void display(string *ds, int *ans, int &k)
{
    for (int i = 0; i < k; ++i)
        cout << ds[ans[i]] << ' ';
    cout << '\n';
}

bool sinh(int *a, int &n, int &k)
{
    int i = k - 1;
    while (i >= 0 && a[i] == n - k + i)
        --i;
    if (i == -1)
        return 0;
    ++a[i];
    while (++i < k)
        a[i] = a[i - 1] + 1;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, kk, *ans;
    string *ds, s;
    cin >> n >> kk;
    ds = new string[n];
    ans = new int[kk];
    int i, j, k;
    k = 0;
    for (i = 0; i < n; ++i)
    {
        cin >> s;
        for (j = 0; j < k; ++j)
            if (ds[j] == s)
                break;
        ds[j] = s;
        if (j == k)
            ++k;
    }
    merge_sort(ds, 0, k - 1);

    for (i = 0; i < kk; ++i)
        ans[i] = i;
    display(ds, ans, kk);
    while (sinh(ans, k, kk))
        display(ds, ans, kk);
    delete[] ds;
    delete[] ans;
    return 0;
}