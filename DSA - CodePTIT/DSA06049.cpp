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
    int n, k;
    cin >> n >> k;
    
    int i, j;
    vector<int> v(n);
    fr(i, 0, n) cin >> v[i];
    sort(v.begin(), v.end());
    int cnt = 0;
    fr(i, 0, n)
    {
    	if(v[i] >= k)
    		break;
    	cnt += lower_bound(v.begin() + i + 1, v.end(), k + v[i]) - v.begin() - i - 1;
	}
	
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
