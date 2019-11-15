#include <bits/stdc++.h>
#define NMAX 6000005
#define INF 0x3f3f3f3f

using namespace std;

ifstream fin("ssm.in");
ofstream fout("ssm.out");

long long N, Smin, Smax = -INF, lastMin = 1, indMin = 1, indMax = 1, partialSum, lastLen = INF;

int main()
{
    fin >> N;
    for (int i = 1; i <= N; i++)
    {
        long long val;
        fin >> val;
        partialSum += val;
        if (partialSum - Smin > Smax || (partialSum - Smin == Smax && i - lastMin < lastLen))
        {
            Smax = partialSum - Smin;
            indMin = lastMin;
            indMax = i;
            lastLen = i - lastMin;
        }
        if (partialSum < Smin)
        {
            Smin = partialSum;
            lastMin = i + 1;
        }
    }
    fout << Smax << " " << indMin << " " << indMax;
    return 0;
}
