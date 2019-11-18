#include <bits/stdc++.h>
#define NMAX 105

using namespace std;

ifstream fin("royfloyd.in");
ofstream fout("royfloyd.out");

int N;
int dist[NMAX][NMAX];

int main()
{
    fin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            fin >> dist[i][j];

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
            {
                if (i == j) continue;
                if (dist[i][k] && dist[k][j])
                    if (dist[i][k] + dist[k][j] < dist[i][j] || dist[i][j] == 0)
                        dist[i][j] = dist[i][k] + dist[k][j];
            }
    for (int i = 1; i <= N; i++, fout << "\n")
        for (int j = 1; j <= N; j++)
            fout << dist[i][j] << " ";
    return 0;
}
