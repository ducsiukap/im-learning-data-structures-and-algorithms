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
    int n, cnt, key, res;
    cin >> n;
    vector<int> v(n);
    
    for(int &i : v) cin >> i;
    sort(v.begin(), v.end());
    
    res = 0;
    for(int i = 0; i < n; )
    {
    	cnt = 1;
    	key = v[i];
    	++i;
    	
    	while (i < n && v[i] == key)
    	{
    		++i;
    		++cnt;
		}
		
		if (cnt > n / 2)
		{
			res = key;
			break;
		}
	}
	
	if (res)
		cout << res << '\n';
	else 
		cout << "NO\n";
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