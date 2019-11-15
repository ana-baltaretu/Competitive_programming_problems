#include <fstream>

using namespace std;

ifstream fin("rucsac.in");
ofstream fout("rucsac.out");

int N, G, weight, profit;
int mxProfit[5][10005];

int main()
{
    fin >> N >> G;
    for (int i = 1; i <= N; i++)
    {
        fin >> weight >> profit;
        for (int j = 0; j <= G; j++)
        {
            if (j >= weight)
                mxProfit[i % 2][j] = max(mxProfit[1 - i % 2][j], mxProfit[1 - i % 2][j - weight] + profit);
            else mxProfit[i % 2][j] = mxProfit[1 - i % 2][j];
        }
    }
    fout << mxProfit[N % 2][G];
    return 0;
}
