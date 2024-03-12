#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void input(vector<int> &set, int &n)
{
    cin >> n;
    set.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> set[i];
    --n;
}

bool check(vector<int> &ans)
{
    int n = ans.size();
    if (n > 1)
        return (ans[n - 1] > ans[n - 2]);
    return true;
}
void Try(vector<vector<int>> &res, vector<int> &set, vector<int> &ans, int &n, int i)
{
    for (int j = 1; j >= 0; --j)
    {
        if (j)
            ans.push_back(set[i]);
        if (i == n)
        {
            if (ans.size() > 1 && check(ans))
                res.push_back(ans);
        }
        else if (check(ans))
            Try(res, set, ans, n, i + 1);
        if (j)
            ans.pop_back();
    }
}

bool cmp(vector<int> &a, vector<int> &b)
{
    string sa, sb;
    for (int &x : a)
        sa += to_string(x) + ' ';
    for (int &x : b)
        sb += to_string(x) + ' ';
    return sa < sb;
}

void output(vector<vector<int>> &res)
{
    sort(res.begin(), res.end(), cmp);
    for (vector<int> &v : res)
    {
        for (int x : v)
            cout << x << ' ';
        cout << '\n';
    }
}

int main()
{
    vector<int> set, ans;
    int n;
    vector<vector<int>> res;
    input(set, n);
    Try(res, set, ans, n, 0);
    output(res);
    system("pause");
    return 0;
}