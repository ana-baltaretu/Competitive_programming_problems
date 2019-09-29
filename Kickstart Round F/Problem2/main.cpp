#include <bits/stdc++.h>
#define NMAX 50005
#define SMAX 1005
using namespace std;

int N, T, cnt, S;
int mp[SMAX];
set<int> st[SMAX], taught[NMAX];
vector <int> v[NMAX];

int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cnt = 0;
        cin >> N >> S;
        for (int i = 1; i <= N; i++)
        {
            int c;
            cin >> c;
            for (int j = 1; j <= c; j++)
            {
                int skill;
                cin >> skill;
                v[i].push_back(skill);

                if (mp[skill] == 0)
                {
                    for (int l = 1; l <= N; l++)
                        if (l != i)
                            st[skill].insert(l);
                    mp[skill] = 1;
                }
                else
                {
                    set <int> :: iterator it = st[skill].find(i);
                    if (it != st[skill].end())
                        st[skill].erase(it);
                }
            }
        }

        for (int i = 1; i <= N; i++)
        {
            for (vector <int> :: iterator it = v[i].begin(); it != v[i].end(); it++)
            {
                int skill = *it;
                for (set<int> :: iterator it2 = st[skill].begin(); it2 != st[skill].end(); it2++)
                {
                    int unknower = *it2;
                    set <int> :: iterator it3 = taught[i].find(unknower);
                    if (it3 == taught[i].end())
                    {
                        cout << i << " " << unknower << endl;
                        cnt++;
                        taught[i].insert(unknower);
                    }
                }
            }
            v[i].clear();
            taught[i].clear();
        }
        for (int i = 1; i <= S; i++)
            if (!st[i].empty())
            {
                mp[i] = 0;
                st[i].clear();
            }
        cout << "Case #" << t << ": " << cnt << endl;
    }
    return 0;
}
