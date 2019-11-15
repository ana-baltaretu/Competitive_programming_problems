#include <bits/stdc++.h>
#define NMAX 100005

using namespace std;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

int N, M, counter;
int visited[NMAX];
vector <int> neighbour[NMAX];

void dfs(int node)
{
    visited[node] = 1;
    for (vector<int> :: iterator it = neighbour[node].begin(); it != neighbour[node].end(); it++)
    {
        int nxt = *it;
        if (!visited[nxt])
            dfs(nxt);
    }
}

int main()
{
    fin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int x, y;
        fin >> x >> y;
        neighbour[x].push_back(y);
        neighbour[y].push_back(x);
    }

    for (int i = 1; i <= N; i++)
        if (!visited[i])
        {
            counter++;
            dfs(i);
        }
    fout << counter << "\n";
    return 0;
}
