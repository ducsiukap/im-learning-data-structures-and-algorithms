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

int BalancePoint(vector<int> &v, int &n)
{
	int total_sum, left_sum, i;
	total_sum = left_sum = 0;
	fr(i, 0, n) total_sum += v[i];
	fr(i, 0, n)
	{
		total_sum -= v[i];
		if (total_sum == left_sum)
			return i + 1;
		left_sum += v[i];
	}
	return -1;
}

void __vippro__() 
{
    int n;
    cin >> n;
    vector<int> v(n);
    
    for (int &i : v)
    	cin >> i;
    
    cout << BalancePoint(v, n) << '\n';
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
