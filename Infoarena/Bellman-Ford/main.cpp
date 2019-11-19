#include <bits/stdc++.h>
#define NMAX 50005
#define INF 0x3f3f3f3f

using namespace std;

ifstream fin("bellmanford.in");
ofstream fout("bellmanford.out");

struct node{
    int nxt, cost;
};

bool isCycle = false;
int N, M;
int dist[NMAX], viz[NMAX];
vector <node> neighbour[NMAX];
queue <int> q;

int main()
{
    fin >> N >> M;
    for (int i = 2; i <= N; i++)
        dist[i] = INF;
    for (int i = 1; i <= M; i++)
    {
        int x, y, c;
        fin >> x >> y >> c;
        neighbour[x].push_back({y, c});
    }
    q.push(1);
    while (!q.empty() && !isCycle)
    {
        int nod = q.front();
        q.pop();
        for (vector <node> :: iterator it = neighbour[nod].begin(); it != neighbour[nod].end(); it++)
        {
            int nxt = (*it).nxt;
            int cst = (*it).cost;
            if (dist[nod] + cst < dist[nxt])
            {
                dist[nxt] = dist[nod] + cst;
                viz[nxt]++;
                if (viz[nxt] >= N)
                    isCycle = true;
                q.push(nxt);
            }
        }
    }
    if (isCycle)
        fout << "Ciclu negativ!";
    else
        for(int i = 2; i <= N; i++)
            fout << dist[i] << " ";

    return 0;
}
