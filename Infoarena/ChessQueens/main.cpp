#include <bits/stdc++.h>
#define NMAX 15
using namespace std;

ifstream fin("damesah.in");
ofstream fout("damesah.out");

int N, total, printed;
int ans[NMAX], col[NMAX], primeDiagonal[2 * NMAX], secondDiagonal[2 * NMAX];

void backTracking(int row, int column)
{
    if (column > N) return;
    if (row == N + 1)
    {
        if (!printed)
        {
            printed = 1;
            for (int i = 1; i <= N; i++)
                fout << ans[i] << " ";
            fout << "\n";
        }
        total++;
        return;
    }

    int pDiag = N - row + column;
    int sDiag = row - 1 + column;
    if (!col[column] && !primeDiagonal[pDiag] && !secondDiagonal[sDiag])
    {
        col[column] = 1;
        primeDiagonal[pDiag] = 1;
        secondDiagonal[sDiag] = 1;
        ans[row] = column;
        backTracking(row + 1, 1);
        col[column] = 0;
        primeDiagonal[pDiag] = 0;
        secondDiagonal[sDiag] = 0;
    }
    backTracking(row, column + 1);
}


int main()
{
    fin >> N;
    backTracking(1, 1);
    fout << total;
    return 0;
}
