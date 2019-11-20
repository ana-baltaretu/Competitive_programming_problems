#include <bits/stdc++.h>
#define NMAX 100005

using namespace std;

ifstream fin("disjoint.in");
ofstream fout("disjoint.out");

int N, M;
int parent[NMAX];

int _parent(int nod)
{
    if (nod == parent[nod])
        return nod;
    return parent[nod] = _parent(parent[nod]);
}

void uniteSets(int x, int y)
{
    int px = _parent(x);
    int py = _parent(y);
    parent[px] = py;
}

int main()
{
    fin >> N >> M;
    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 1; i <= M; i++)
    {
        int type, x, y;
        fin >> type >> x >> y;
        if (type == 1)
        {
            uniteSets(x, y);
        }
        else
        {
            if (_parent(x) == _parent(y))
                fout << "DA\n";
            else fout << "NU\n";
        }
    }
    return 0;
}
