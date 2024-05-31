#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fr(i, a, b) for (int i = a; i < b; ++i)
#define fe(i, a, b) for (int i = a; i <= b; ++i)
#define dr(i, a, b) for (int i = a; i > b; --i)
#define de(i, a, b) for (int i = a; i >= b; --i)

#define vt(x) vector<x>
#define all(x) x.begin(), x.end();

#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define run() int T; cin >> T; while(T--)

#define out(x, n, sep) fr (itr, 0, n) cout << x[itr] << sep;
#define in(x, n) fr(itr, 0, n) cin >> x[itr];
#define reset(x, n, value) fr (itr, 0, n) x[itr] = value;

#define __ducsjukap__ int main()

int miniumInsert(vt(int) &v, int &n)
{
	vt(int) dp(n, 1);
	
	fr (i, 1, n)
		fr (j, 0, i)
			if (v[i] > v[j])
				dp[i] = max(dp[i], dp[j] + 1);
	
	int maxList = 1;
	fr (i, 1, n)
		maxList = max(maxList, dp[i]);
		
	return n - maxList;
}

void vippro()
{
	int n;
	cin >> n;
	
	vt(int) v(n);
	in(v, n);
	
	cout << miniumInsert(v, n) << '\n';
}

__ducsjukap__
{
	faster();
	run()
		vippro();
	return 0;
}
