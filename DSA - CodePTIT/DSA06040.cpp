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
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<ll> v1(n1), v2(n2), v3(n3), res;
    
    for(ll &i : v1) cin >> i;
    for(ll &i : v2) cin >> i;
    for(ll &i : v3) cin >> i;
    
    int i1, i2, i3;
    i1 = i2 = i3 = 0;
    while(i1 < n1 && i2 < n2 && i3 < n3)
    {
    	if(v1[i1] == v2[i2] && v1[i1] == v3[i3])
    	{
    		res.push_back(v1[i1]);
    		++i1;
    		++i2;
    		++i3;
		}
		
		else if(v1[i1] < v2[i2]) 
			++i1;
		else if(v2[i2] < v3[i3])
			++i2;
		else
			++i3;
	}
	
	if(res.empty())
		cout << -1;
	else
		for(ll &i : res) cout << i << ' ';
	
	cout << '\n';
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
