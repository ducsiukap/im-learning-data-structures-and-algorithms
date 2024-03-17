#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void __vippro__()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v) cin >> i;
    int ans = 2e6, tmp;
    for(int i = 0; i < n; ++i)
    	for(int j = i + 1; j < n; ++j)
    	{
    		tmp = v[i] + v[j];
    		if(abs(tmp) < abs(ans))
    			ans = tmp;
		}
	cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        __vippro__();
    return 0;
}
