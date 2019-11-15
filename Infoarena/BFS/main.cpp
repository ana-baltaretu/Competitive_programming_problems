#include <bits/stdc++.h>
#define NMAX 100005
#define INF 9999999999

using namespace std;

ifstream fin("bfs.in");
ofstream fout("bfs.out");

int N, M, S;
long long dist[NMAX];
vector <int> neighbour[NMAX];
queue <int> q;

void bfs(int source)
{
    dist[source] = 0;
    q.push(source);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (vector<int> :: iterator it = neighbour[node].begin(); it != neighbour[node].end(); it++)
        {
            int nxt = *it;
            if (dist[node] + 1 < dist[nxt])
            {
                dist[nxt] = dist[node] + 1;
                q.push(nxt);
            }
        }
    }
}

int main()
{
    fin >> N >> M >> S;
    for (int i = 0; i < M; i++)
    {
        int x, y;
        fin >> x >> y;
        neighbour[x].push_back(y);
    }

    for (int i = 1; i <= N; i++)
        dist[i] = INF;

    bfs(S);

    for (int i = 1; i <= N; i++)
        if (dist[i] == INF)
            fout << -1 << " ";
        else fout << dist[i] << " ";
    return 0;
}
