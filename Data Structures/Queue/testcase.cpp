#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main()
{
    ofstream fout("test5.txt");
    fout.clear();
    srand(time(0));
    fout << 3 << '\n';
    for (int i = 0; i < 3; ++i)
    {
        int n;
        cin >> n;
        fout << n << '\n';
        for (int i = 0; i < n; ++i)
            fout << rand() % int(1e10) << ' ';
        fout << '\n';
        for (int j = 0; j < 10; ++j)
            fout << rand() % int(1e15) << ' ';
        fout << '\n';
    }
    fout.close();
    system("pause");
}
