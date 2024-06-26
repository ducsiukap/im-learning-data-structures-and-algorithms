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

	

bool dfs(vt(vt(int)) &ke, vt(bool) &unused, int &n, int u, int par)
{
	unused[u] = false;
	
	for (int &v : ke[u])
		if (unused[v])
		{
			if (dfs(ke, unused, n, v, u))
				return true;
		}
		else if (v != par)
			return true;
	
	return false;
 } 

bool chutrinh(vt(vt(int)) &ke, int &n)
{
	vt(bool) unused(n + 1, true);
	fe (i, 1, n)
		if (unused[i])
			if (dfs(ke, unused, n, i, 0))
				return true;
	return false;
}

void vippro()
{
	int n, ne;
	cin >> n >> ne;
	
	vt(vt(int)) ke(n + 1);
	
	fr(i, 0, ne)
	{
		int u, v;
		cin >> u >> v;
		ke[u].push_back(v);
		ke[v].push_back(u);
	}
	
	if (chutrinh(ke, n))
		cout << "YES";
	else 
		cout << "NO";
	
	cout << '\n';
}

__ducsjukap__
{
	faster();
	run()
		vippro();
	return 0;
}
