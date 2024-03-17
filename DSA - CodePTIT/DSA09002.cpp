#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
using namespace std;


int main()
{
	int n, a, b; 
	vector<set<int>> v;
	cin >> n;
	v.resize(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j < n; ++j)
		{
			cin >> a;
			if(a > i)
				v[i].insert(a);
		}
	}
	for(int i = 1; i <= n; ++i)
		if(!v[i].empty())
			for(int e : v[i])
				cout << i << ' ' << e << '\n';
	cout << '\n';
	
}
