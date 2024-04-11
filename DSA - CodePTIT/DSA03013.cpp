// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define code_no_bug() int main()
#define fr(i, a, b) for (int i = a; i < b; ++i)
#define fd(i, a, b) for (int i = a; i <= b; ++i)
#define dr(i, a, b) for (int i = a; i > b; --i)
#define dd(i, a, b) for (int i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()

void __ducsjkap_vippro__()
{
    int d;
    string s;
    cin >> d >> s;

    vi Freq(26, 0);
    for (char &i : s)
        ++Freq[i - 'A'];

    int maxFre = Freq[0];
    fr(i, 1, 26)
        maxFre = max(maxFre, Freq[i]);

    int max_accepted_freq = s.size() - (d - 1) * (maxFre - 1);

    if (maxFre <= max_accepted_freq)
        cout << "1\n";
    else
        cout << "-1\n";
}

code_no_bug()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T)
    {
        --T;
        __ducsjkap_vippro__();
    }

    return 0;
}
// * Code by Ducsjukapvippro