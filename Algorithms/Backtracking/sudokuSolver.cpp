// * Code by Ducsjukapvippro
// * dont cry bae =))
// * neu ngay mai khong den thi sao?

/*
Given a partially filled 9×9 2D array ‘grid[9][9]’,
the goal is to assign digits (from 1 to 9) to the empty cells
so that every row, column, and subgrid of size 3×3
contains exactly one instance of the digits from 1 to 9.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

#define __ducsjukap__ int main()
#define faster()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define run() \
    int T;    \
    cin >> T; \
    while (T--)
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define fi first
#define se second
#define pb(a) push_back(a)
#define fr(i, a, b) for (int i = a; i < b; ++i)
#define fe(i, a, b) for (int i = a; i <= b; ++i)
#define dr(i, a, b) for (int i = a; i > b; --i)
#define de(i, a, b) for (int i = a; i >= b; --i)
#define in(x, n) fr(itr, 0, n) cin >> x[itr]
#define out(x, n, sep) fr(itr, 0, n) cout << x[itr] << sep
#define reset(x, n, value) fr(itr, 0, n) x[itr] = value

bool check(vt(vt(int)) & sudoku, int &i, int &j)
{
    // check row and col
    fr(x, 0, 9)
    {
        if ((sudoku[i][x] == sudoku[i][j]) && (x != j))
            return false;
        if ((sudoku[x][j] == sudoku[i][j]) && (x != i))
            return false;
    }

    // check subgrid of 3x3
    int row, col;
    row = i / 3 * 3;
    col = j / 3 * 3;
    fr(r, row, row + 3)
    {
        if (r == i)
            continue;
        fr(c, col, col + 3)
        {
            if (c == j)
                continue;
            if (sudoku[r][c] == sudoku[i][j])
                return false;
        }
    }

    // sudoku[i][j] is ok!
    return true;
}

vt(vt(int)) sudoku_solved;
void Try(vt(vt(int)) & sudoku, int i, int j)
{
    if (i == 9)
    {
        sudoku_solved = sudoku;
        return;
    }

    if (sudoku[i][j] != 0)
    {
        if (j == 8)
            Try(sudoku, i + 1, 0);
        else
            Try(sudoku, i, j + 1);
    }

    else
    {
        fr(solution, 1, 10)
        {
            sudoku[i][j] = solution;
            if (check(sudoku, i, j))
            {
                if (j == 8)
                    Try(sudoku, i + 1, 0);
                else
                    Try(sudoku, i, j + 1);
            }
            sudoku[i][j] = 0;
        }
    }
}

void __vippro__()
{
    vt(vt(int)) sudoku(9, vt(int)(9));

    for (vt(int) & v : sudoku)
        in(v, 9);

    sudoku_solved.clear();
    Try(sudoku, 0, 0);
    if (sudoku_solved.empty())
        cout << "cant solve!\n";
    else
    {
        for (vt(int) & v : sudoku_solved)
        {
            for (int &x : v)
                cout << x << ' ';
            cout << '\n';
        }
    }
}

__ducsjukap__
{
    faster();
    run()
        __vippro__();
    return 0;
}
// * Code by Ducsjukapvippro
