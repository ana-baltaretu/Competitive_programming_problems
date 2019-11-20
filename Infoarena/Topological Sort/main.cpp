#include <bits/stdc++.h>
#define NMAX 50005

using namespace std;

ifstream fin("sortaret.in");
ofstream fout("sortaret.out");

int N, M, K;
int visited[NMAX], answer[NMAX];
vector <int> neighbour[NMAX];
stack <int> st;

void dfs(int node)
{
    visited[node] = 1;
    for (vector <int> :: iterator it = neighbour[node].begin(); it != neighbour[node].end(); it++)
    {
        int nxt = *it;
        if (!visited[nxt])
            dfs(nxt);
    }
    st.push(node);
}

int main()
{
    fin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int x, y;
        fin >> x >> y;
        neighbour[x].push_back(y);
    }

    for (int i = 1; i <= N; i++)
        if (!visited[i])
            dfs(i);

    while (!st.empty())
    {
        fout << st.top() << " ";
        st.pop();
    }
    return 0;
}
