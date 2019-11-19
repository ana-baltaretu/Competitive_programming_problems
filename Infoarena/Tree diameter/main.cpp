#include <bits/stdc++.h>
#define NMAX 100005

using namespace std;

ifstream fin("darb.in");
ofstream fout("darb.out");

int N;
int firstTrip[NMAX], secondTrip[NMAX];
vector <int> neighbour[NMAX];

int dfs(int nod, int trip[])
{
    int mx = nod;
    for (vector <int> :: iterator it = neighbour[nod].begin(); it != neighbour[nod].end(); it++)
    {
        int nxt = *it;
        if (!trip[nxt])
        {
            trip[nxt] = trip[nod] + 1;
            int nxtMX = dfs(nxt, trip);
            if (trip[nxtMX] > trip[mx])
                mx = nxtMX;
        }
    }
    return mx;
}


int main()
{
    fin >> N;
    for (int i = 1; i < N; i++)
    {
        int x, y;
        fin >> x >> y;
        neighbour[x].push_back(y);
        neighbour[y].push_back(x);
    }
    firstTrip[1] = 1;
    int mx = dfs(1, firstTrip);
    secondTrip[mx] = 1;
    fout << secondTrip[dfs(mx, secondTrip)];
    return 0;
}
