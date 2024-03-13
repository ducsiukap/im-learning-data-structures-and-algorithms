// * Algorithm: interpolation_search

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Interpolation_search(vector<int> &v, int low, int high, int x)
{
	int mid;
	
	while (low <= high && x >= v[low] && x <= v[high])
	{
		if (v[low] == v[high])
			return v[low] == x;
		
		mid = low + (double)(x - v[low]) * (high - low) / (v[high] - v[low]);
		
		if (v[mid] == x)
			return mid;
			
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

int main()
{
	vector<int> v = {9, 7, 3, 5, 2, 4, 1};
	
	sort(v.begin(), v.end()); // interpolation_search algorithm work with sorted array
	
	cout << "Interpolation Search:\n\n";
	
	// v = {1, 2, 3, 4, 5, 7, 9}
	int idx = Interpolation_search(v, 0, v.size() - 1, 3); // idx = 2
	if (idx == -1) // false
		cout << "Not Found 3!\n";
	else
		cout << "Found 3 at index " << idx << '\n';
		
	idx  = Interpolation_search(v, 0, v.size() - 1, 6); // idx = -1
	if (idx == -1) // true
		cout << "Not Found 6\n";
	else 
		cout << "Found 6 at index " << idx << '\n';
		
	return 0;
}
