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

bool check(vt(int) &v, int n, int s)
{
	vt(bool) dp(s + 1, false);
	
	dp[0] = true;
	fr(i, 0, n)
		de(j, s, v[i])
			dp[j] = (dp[j] || dp[j - v[i]]);
	return dp[s];
}

void vippro()
{
	int n, s;
	cin >> n >> s;
	 
	vt(int) v(n);
	in(v, n);
	
	cout << (check(v, n, s) ? "YES" : "NO") << '\n';
}

__ducsjukap__
{
	faster();
	run()
		vippro();
	return 0;
}
