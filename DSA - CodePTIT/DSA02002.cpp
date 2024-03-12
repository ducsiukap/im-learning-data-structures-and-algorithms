#include <iostream>
#include <vector>
using namespace std;

void process(vector<vector<int>> &v, int &n)
{
    int j;
    for (int i = 1; i < n; ++i)
    {
        v[i].resize(n - i);
        for (j = 0; j < n - i; ++j)
            v[i][j] = v[i - 1][j] + v[i - 1][j + 1];
    }
}

void input(vector<vector<int>> &v, int &n)
{
    cin >> n;
    v.resize(n);
    v[0].resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[0][i];
}

void ouput(vector<vector<int>> &v, int &n)
{
    --n;
    int j;
    for (int i = n; i >= 0; --i)
    {
        cout << '[';
        for (j = 0; j < n - i; ++j)
            cout << v[i][j] << ' ';
        cout << v[i][j] << "] ";
        v[i].clear();
    }
    v.clear();
    cout << '\n';
}

int main()
{
    int t, n;
    vector<vector<int>> v;
    cin >> t;
    do
    {
        input(v, n);
        process(v, n);
        ouput(v, n);
    } while (--t);

    return 0;
}