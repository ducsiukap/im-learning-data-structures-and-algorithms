// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i <= b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

int Binary_search(vector<pair<int, int>> &v, int low, int high, int x)
{
	int mid;
	while(low <= high)
	{
		mid = low + (high - low) / 2;
		
		if(v[mid].first == x)
			return mid;
		else if(v[mid].first < x)
			low = mid + 1;
		else 
			high = mid - 1;
	}
	return 0;
}

void __vippro__() 
{
    int n, k, x, i;
    map<int, int> mp;
    cin >> n >> k;
    
    fr(i, 0, n)
    {
    	cin >> x;
    	++mp[x];
	}
	
	vector<pair<int, int>> v;
	for(pair<int, int> p : mp)
		v.push_back(p);
		
	n = v.size();
	ll res = 0;
	fr(i, 0, n)
	{
		if(v[i].first >= k)
			break;
		else if(v[i].first + v[i].first == k)
			res += v[i].second * (v[i].second - 1) / 2;
		else
		{
			x = Binary_search(v, i + 1, n - 1, k - v[i].first);
			if(x)
				res += v[x].second * v[i].second;
		}
	}
	
	cout << res << '\n';	
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
