#include<bits/stdc++.h>
using namespace std;
void insertion_sort(vector<int> &v, int &n, int &x)
{
	int key;
	for(int i = 1; i < n; ++i)
	{
		key = abs(x - v[i]);
		for(int j = i - 1; j >= 0; --j)
			if(abs(x - v[j]) > key)
				swap(v[j], v[j + 1]);
			else break;
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, x;
		cin >> n >> x;
		vector<int> v(n);
		for(int &i : v) cin >> i;
		insertion_sort(v, n, x);	
		for(int i : v) cout << i << ' ';
		cout << '\n';
	}
}
