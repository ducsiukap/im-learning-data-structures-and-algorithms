// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (int i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i <= b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

bool cmp(pair<int, int> &a, pair<int, int> &b) { return a.first < b.first; }

int largestDistance(vector<pair<int, int>> &v, int &n)
{
	if(n == 1)
		return -1e9;
		
	sort(v.begin(), v.end(), cmp);
	
	int ans = v[1].second - v[0].second;
	int minPos = min(v[0].second, v[1].second);
	
	fr(i, 2, n)
	{
		ans = max(ans, v[i].second - minPos);
		minPos = min(minPos, v[i].second);
	}
	
	return ans;
}

void __vippro__() 
{
	int n, x;
    vector<pair<int, int>> v;
    
	cin >> n;
	
    fr(i, 0, n)
    {
    	cin >> x;
    	v.push_back({x, i});
	}
	
	cout << largestDistance(v, n) << '\n';
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
