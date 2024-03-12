#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cv
{
    int BEG, END;
};

bool cmp(cv &a, cv &b)
{
    if (a.END == b.END)
        return a.BEG < b.BEG;
    return a.END < b.END;
}

void input(vector<cv> &v, int &n)
{
    cin >> n;
    v.resize(n);
    int i;
    for (i = 0; i < n; ++i)
        cin >> v[i].BEG;
    for (i = 0; i < n; ++i)
        cin >> v[i].END;
}
void output(vector<cv> &v, int &n)
{
    sort(v.begin(), v.end(), cmp);
    int res = 1, last_work_end_time = v[0].END;
    for (int i = 1; i < n; ++i)
        if (v[i].BEG >= last_work_end_time)
        {
            last_work_end_time = v[i].END;
            ++res;
        }
    cout << res << '\n';
    v.clear();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    vector<cv> v;
    cin >> t;
    do
    {
        input(v, n);
        output(v, n);
    } while (--t);
    return 0;
}