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
int m  = 1e9 + 7;
void vippro()
{
	int n, k;
	
	cin >> n >> k;
	vt(vt(int)) c(n + 1, vt(int)(n + 1, 0)); // v[i][j] = c(i, j)
	// c(n, k) = n!/(k!.(n - k))!)
	
	fe(i, 0, n)
		fe(j, 0, i)
			if (j == 0 || j == i)
				c[i][j] = 1;
			else
			{
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
				c[i][j] %= m;
			}
	
	cout << c[n][k] << '\n';
	
}

__ducsjukap__
{
	faster();
	run()
		vippro();
	return 0;
}
