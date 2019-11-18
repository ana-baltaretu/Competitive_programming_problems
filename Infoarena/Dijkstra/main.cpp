#include <bits/stdc++.h>
#define NMAX 50005
#define INF 0x3f3f3f3f
#define pii pair<int, int>

using namespace std;

ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

struct item
{
    int node, cost;

    bool operator < (const item &other) const {
        return cost > other.cost;
    }
};

int N, M;
int dist[NMAX];
priority_queue <item> pq;
vector <pii> neighbour[NMAX];

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

    pq.push({1, 0});
    while (!pq.empty())
    {

        int node = pq.top().node;
        int cost = pq.top().cost;
        pq.pop();
        if (cost != dist[node]) continue;
        for (vector <pii> :: iterator it = neighbour[node].begin(); it != neighbour[node].end(); it++)
        {
            int nxt = (*it).first;
            int cst = (*it).second;
            if (dist[node] + cst < dist[nxt])
            {
                dist[nxt] = dist[node] + cst;
                pq.push({nxt, dist[nxt]});
            }
        }
    }

    for (int i = 2; i <= N; i++)
        if (dist[i] == INF)
            fout << "0 ";
        else fout << dist[i] << " ";

    return 0;
}
