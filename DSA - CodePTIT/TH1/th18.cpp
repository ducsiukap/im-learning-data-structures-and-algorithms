// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i <= b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

void __vippro__() 
{
    int n, k, i, j, cnt;
    cin >> n >> k;
    vector<int> v(1001, 0);
    fr(i, 0, n)
    {
    	cin >> j;
    	++v[j];
	}
	cnt = 0;
	fd(i, 0, k / 2)
		if (i + i == k)
			cnt += (v[i] - 1) * v[i] / 2;
		else 
			cnt += v[i] * v[k - i];
	cout << cnt << '\n';
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
