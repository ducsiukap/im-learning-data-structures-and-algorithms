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
    vector<int> v(n);
    
    int i, j;
    fr(i, 0, n) cin >> v[i];
    fr(i, 0, n - 1)
    {
    	fr(j, i + 1, n)
    		if(v[j] < v[i])
    			swap(v[i], v[j]);
    	cout << "Buoc " << i + 1 << ':';
    	fr(j, 0, n) cout << ' ' << v[j];
    	cout << '\n';
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
