// * Algorithm: Fibonacci Search

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getFiboArr(int &n)
{
	vector<int> fib;
	if (n == 0)
		return fib;
	fib.push_back(0);
	if (n == 1)
		return fib;
	fib.push_back(1);
	
	int i = 1, fibo;
	while (1)
	{
		fibo = fib[i] + fib[i - 1];
		++i;
		
		if (fibo <= n)
			fib.push_back(fibo);
		else
			break;
	}
	
	return fib;
}

bool Fibonacci_search(vector<int> &v, int low, int high, int x)
{
	int len, mid, i;
	len = low - high;
	vector<int> fi = getFiboArr(len);
	i = fi.size() - 1;
	
	while(i >= 0)
	{
		mid = low + fi[i];
		
		if (v[mid] == x)
			return true;
		
		if (v[mid] < x)
			low = mid + 1;
		else
			high = mid - 1;
		
		len = high - low;
		while (i >= 0 && fi[i] > len)
			--i;
	}
	return false;
}

int main()
{
	vector<int> v = {9, 7, 3, 5, 2, 4, 1};
	
	sort(v.begin(), v.end()); // interpolation_search algorithm work with sorted array
	
	cout << "Fibonacci Search:\n\n";
	
	// v = {1, 2, 3, 4, 5, 7, 9}
	if (Fibonacci_search(v, 0, v.size() - 1, 3)) // true
		cout << "Found 3\n";
	else
		cout << "Not Found 3\n";
		
	if (Fibonacci_search(v, 0, v.size() - 1, 6)) // false
		cout << "Found 6\n";
	else
		cout << "Not Found 6\n";
		
	return 0;
}
