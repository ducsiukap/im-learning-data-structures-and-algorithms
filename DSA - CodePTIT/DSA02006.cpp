#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void input(int &n, int &k, vector<int> &set)
{
    cin >> n >> k;
    set.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> set[i];
    sort(set.begin(), set.end());
}

void Try(vector<vector<int>> &v, vector<int> &set, vector<int> &ans, int i, int &n, int &k, int sum)
{
    for (int j = 1; j >= 0; --j)
    {
        if (j)
        {
            ans.push_back(set[i]);
            sum += set[i];
        }
        if (i == n - 1)
        {
            if (sum == k)
                v.push_back(ans);
        }
        else if (sum <= k)
            Try(v, set, ans, i + 1, n, k, sum);
        if (j)
        {
            sum -= set[i];
            ans.pop_back();
        }
    }
}

void output(vector<vector<int>> &v)
{
    if (v.empty())
        cout << "-1\n";
    else
    {
        // sort(v.begin(), v.end());
        int n, i;
        for (vector<int> &x : v)
        {
            n = x.size();
            cout << '[';
            for (i = 0; i < n; ++i)
            {
                cout << x[i];
                if (i != n - 1)
                    cout << ' ';
            }
            cout << "] ";
        }
        cout << '\n';
    }
}

int main()
{
    int t, n, k;
    vector<int> set, ans;
    vector<vector<int>> v;
    cin >> t;
    do
    {
        input(n, k, set);
        Try(v, set, ans, 0, n, k, 0);
        output(v);
        // free memory
        set.clear();
        ans.clear();
        v.clear();
    } while (--t);
}