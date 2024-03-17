#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, s, k;
		cin >> n >> s >> k;
		--s;
		vector<int> v(n);
		for(int &i : v) cin >> i;
		if(v[s] > k)
			cout << "-1\n";
		else if(v[s] == k)
			cout << s + 1 << '\n';
		else
		{
			int st = s;
			long long tmp = 0;
			while(st >= 0)
			{
				tmp += v[st];
				if(tmp > k)
					break;
				--st;
			}
			cout << st + 2 << '\n';
		}
	}
}
