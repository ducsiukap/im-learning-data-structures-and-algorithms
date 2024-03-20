#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <iomanip>

using namespace std;

ifstream ftest("test5.txt");

void init(vector<long long> &v, int &n)
{
	ftest >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i)
		ftest >> v[i];
	sort(v.begin(), v.end());
}

bool search_func(vector<long long> v, int st, int en, long long x) // ternary_search
{
	int f1, f2, f3, mid;
	int v_size = en - st;

	f1 = 0;
	f2 = f3 = 1;
	while (f3 + f2 <= v_size)
	{
		f1 = f2;
		f2 = f3;
		f3 = f1 + f2;
	}

	while (st <= en && f3 >= 0)
	{
		mid = st + f3;

		if (v[mid] == x)
			return true;
		if (v[mid] < x)
			st = mid + 1;
		else
			en = mid - 1;
		v_size = en - st;

		while (f3 > v_size)
		{
			f3 = f2;
			f2 = f1;
			f1 = f3 - f2;
		}
	}
	return false;
}

int main()
{
	int T;
	ftest >> T;
	while (T--)
	{
		int n;
		vector<long long> v;
		init(v, n);
		long long target;
		clock_t st = clock();
		for (int i = 0; i < 10; ++i)
		{
			ftest >> target;
			cout << search_func(v, 0, n - 1, target);
		}
		clock_t en = clock();
		cout << '\n'
			 << en - st << '\n';
	}
	system("pause");
}
