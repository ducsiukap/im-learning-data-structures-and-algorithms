// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (int i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i <= b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

int n;
int a[100], x[100];
bool ok = false;

bool init()
{
	cin >> n;
	
	int tmp = 0;
	fr(i, 0, n)
	{
		cin >> a[i];
		tmp += a[i];	
	}
	
	return tmp % 2 == 0;
}

bool check()
{
	int sum = 0;
	fr(i, 0, n)
		if (x[i])
			sum += a[i];
		else
			sum -= a[i];
	return sum == 0;	
}

void Try(int i)
{
	if (ok)
		return;
	fr(j, 0, 2)
	{
		x[i] = j;
		
		if (i == n)
		{
			ok = true;
		}
		else 
			Try(i + 1);
	}
}

void __vippro__() 
{
	if (init())
	{
		--n;
		Try(0);
		
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	
	else
		cout << "NO\n";
}

__ducsjukap__()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    dr(T, T, 0)
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
