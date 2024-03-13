// * Algorithm: ternary_search

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Ternary_search(vector<int> &v, int low, int high, int x)
{
	int mid1, mid2;
	while(low <= high)
	{
		mid1 = low + (high - low) / 3;
		mid2 = low + 2 * (high - low) / 3;
		
		if (v[mid1] == x || v[mid2] == x)
			return true;
			
		else if (v[mid1] < x) // x in v[(mid1 + 1)...(mid2 - 1)] or v[(mid2 + 1)...(high)] 
		{
			low = mid1 + 1;
			
			if (v[mid2] < x) // x in v[(mid2 + 1)...high]
				low = mid2 + 1;
			else // x in v[(mid1 + 1)...(mid2-1)]
				high = mid2 - 1;	
		} 
		else // x in v[low...(mid1 - 1)]
			high = mid1 - 1;
	}
	// if x not in v[low...high]
	return false;
}

int main()
{
	vector<int> v = {9, 7, 3, 5, 2, 4, 1};
	
	sort(v.begin(), v.end()); // ternary_search work with sorted array
	
	cout << "Ternary Search\n\n";
	
	if (Ternary_search(v, 0, v.size() - 1, 3)) // true
		cout << "Found 3\n";
	else 
		cout << "Not Found 3\n"; 
		
	if (Ternary_search(v, 0, v.size() - 1, 6)) // false
		cout << "Found 6\n";
	else
		cout << "Not Found 6\n";
		
	return 0;
}
