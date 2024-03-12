#include <iostream>
using namespace std;

void display(char *kt, int *ans, int &k)
{
    for (int i = 0; i < k; ++i)
        cout << kt[ans[i]];
    cout << '\n';
}

bool sinh(int *ans, int &n, int &k)
{
    int i = k - 1;
    while (i >= 0 && ans[i] == n - k + i)
        --i;
    if (i == -1)
        return false;
    ++ans[i];
    while (++i < k)
        ans[i] = ans[i - 1] + 1;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char kt[16];
    int t, n, k;
    for (t = 0; t < 16; ++t)
        kt[t] = 'A' + t;
    int *ans;
    cin >> t;
    while (t)
    {
        --t;
        cin >> n >> k;
        ans = new int[k];
        for (int i = 0; i < k; ++i)
            ans[i] = i;
        display(kt, ans, k);
        while (sinh(ans, n, k))
            display(kt, ans, k);
        delete[] ans;
    }
    return 0;
}