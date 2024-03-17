#include<bits/stdc++.h>
using namespace std;
bool a[1000000];
void Init()
{
	for(int i = 0; i < 1000001; ++i)
		a[i] = 1;
	a[0] = a[1] = 0;
	for(int i = 2; i <= 1000; ++i)
	{
		if(a[i])
			for(int j = i * i; j < 1000001; j += i)
				a[j] = 0;
	}
}
int main()
{
	Init();
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		if(n < 4)
			cout << "-1\n";
		else if(a[2] && a[n - 2])
			cout << 2 << ' ' << n - 2 << '\n';
		else
		{
			bool ok = true;
			for(int x = 3; x <= n / 2; x += 2)
				if(a[x] && a[n - x])
				{
					cout << x << ' ' << n - x << '\n';
					ok = 0;
					break;
				}
			if(ok) cout << "-1\n";
		}
	}
}
