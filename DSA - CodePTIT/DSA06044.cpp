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
    int n;
    cin >> n;
    
    vector<int> v(n), v1, v2;
    for(int &i : v) cin >> i;
    
    int i;
    for (i = 0; i < n; i += 2)
    	v1.push_back(v[i]);
    for (i = 1; i < n; i += 2)
    	v2.push_back(v[i]);
    	
    sort(v1.begin(), v1.end());
    sort(v2.rbegin(), v2.rend());

	n = (n + 1) / 2;
	fr(i, 0, n)
	{
		cout << v1[i] << ' ';
		if (i < v2.size()) 
			cout << v2[i] << ' ';
	}
}

__ducsjukap__()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
//    cin >> T;
//    dr(T, T, 0)
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
