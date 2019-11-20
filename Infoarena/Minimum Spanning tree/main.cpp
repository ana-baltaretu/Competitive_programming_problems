#include <bits/stdc++.h>
#define NMAX 200005
#define pii pair <int, int>

using namespace std;

ifstream fin("apm.in");
ofstream fout("apm.out");

struct edgesSorter{
    int node1, node2, cost;

    bool operator < (const edgesSorter &other) const{
        return cost > other.cost;
    }
};

int N, M, minimumSum, edgeCount;
int prnt[NMAX];
priority_queue <edgesSorter> sortedEdges;
pii ans[NMAX]; /// max N-1 edges

int parent(int node)
{
    if (prnt[node] == node)
        return node;
    return prnt[node] = parent(prnt[node]);
}

int parentX, parentY;

bool needsToUnite(int x, int y)
{
    parentX = parent(x);
    parentY = parent(y);
    if (parentX != parentY)
        return true;
    return false;
}

void unite(int x, int y, int edgeCost)
{
    minimumSum += edgeCost;
    edgeCount++;
    ans[edgeCount] = {x, y};
    prnt[parentX] = parentY;
}

int main()
{
    fin >> N >> M;
    for (int i = 1; i <= N; i++)
        prnt[i] = i;
    for (int i = 1; i <= M; i++)
    {
        int x, y, c;
        fin >> x >> y >> c;
        sortedEdges.push({x, y, c});
    }

    while (!sortedEdges.empty())
    {
        int x = sortedEdges.top().node1;
        int y = sortedEdges.top().node2;
        int c = sortedEdges.top().cost;
        sortedEdges.pop();
        if (needsToUnite(x, y))
            unite(x, y, c);
    }
    fout << minimumSum << "\n" << edgeCount << "\n";
    for (int i = 1; i <= edgeCount; i++)
        fout << ans[i].first << " " << ans[i].second << "\n";
    return 0;
}
