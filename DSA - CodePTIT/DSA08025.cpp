// * Code by Ducsjukapvippro
// * dont cry bae =))
// * minh luon luon khong biet tat ca moi thu
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

#define __ducsjukap__() int main()
#define fr(i, a, b) for (int i = a; i < b; ++i)
#define fd(i, a, b) for (i = a; i <= b; ++i)
#define dr(i, a, b) for (i = a; i > b; --i)
#define dd(i, a, b) for (i = a; i >= b; --i)
typedef long long ll;
typedef long double ld;

struct nowPos
{
    char row, col;
    int step;
    nowPos(char co, char ro, int s) : row(ro), col(co), step(s) {}
};

const int r[] = {-1, 1, 2, 2, 1, -1, -2, -2};
const int c[] = {2, 2, 1, -1, -2, -2, -1, 1};
void __vippro__()
{
    vector<vector<bool>> unused(8, vector<bool>(8, true)); // ban co vua
    queue<nowPos> q;

    string end;
    cin >> end;
    q.push(nowPos(end[0], end[1], 0));
    cin >> end; // goal

    nowPos np(nowPos(0, 0, 0));
    while (1)
    {
        np = q.front();
        q.pop();
        if (np.row == end[1] && np.col == end[0])
        {
            cout << np.step << '\n';
            return;
        }
        unused['8' - np.row][np.col - 'a'] = false;
        /*
        *huong di chuyen cua quan Ma~
          1 2 3 4 5 6 7 8
        A . . . . . . . .
        B . . . . . . . .
        C . . . X . . . .
        D . X . M . X . .
        E . . . X . . . .
        F . . . . . . . .
        G . . . . . . . .
        H . . . . . . . .
        */
        fr(i, 0, 8)
        {
            np.row += r[i];
            np.col += c[i];
            if (np.row >= '1' && np.row <= '8' && np.col >= 'a' && np.col <= 'h')
                q.push(nowPos(np.col, np.row, np.step + 1));
            np.row -= r[i];
            np.col -= c[i];
        }
    }
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