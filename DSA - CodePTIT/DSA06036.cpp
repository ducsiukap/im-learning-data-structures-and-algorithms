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

bool Tripple(vector<int> &v, int &n, int &k)
{
	int i, j, l;
	ll res;
	fr(i, 0, n - 2)
	{
		if(v[i] > k)
			break;
			
		res = v[i];
		
		j = i + 1;
		l = n - 1;
		
		while(j < l && v[j] < v[l])
		{
			res += v[j] + v[l];
			
			if(res == k)
				return true;
			else if(res < k)
			{
				res -= v[j] + v[l];
				++j;
			}
			else
			{
				res -= v[j] + v[l];
				--l;
			}
		}
	}
	return false;
}

void __vippro__() 
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    
    for(int &i : v)
    	cin >> i;
    	
    sort(v.begin(), v.end());
    
    if(Tripple(v, n, k))
    	cout << "YES\n";
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
