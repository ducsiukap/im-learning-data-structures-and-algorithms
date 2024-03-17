#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		bool ok[10];
		int n;
		for(int i = 0; i < 10; ++i)
			ok[i] = false;
		cin >> n;
		string s;
		while(n--)
		{
			cin >> s;
			for(int i = 0; i < s.size(); ++i)
				ok[s[i] - '0'] = true;
		}
		
		for(int i = 9; i >= 0; --i)
			if(ok[i])
				cout << i << ' ';
		cout << '\n';
	}
}
