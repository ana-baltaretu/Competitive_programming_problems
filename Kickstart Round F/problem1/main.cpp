#include <bits/stdc++.h>
#define NMAX 1005
#define INF 0x3f3f3f3f

using namespace std;

int T, N, K, mn;
int a[NMAX], dp[NMAX][NMAX];

struct str{
    int pos, lastChangedPos, numberOfChanges, numberOfKJumps;

    bool operator < (const str &other)const
    {
        return pos > other.pos;

    }
};

priority_queue <str> pq;

int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        mn = INF;
        cin >> N >> K;
        for (int i = 1; i <= N; i++)
            cin >> a[i];
        pq.push({1, 1, 0, 0});
        while (!pq.empty())
        {
            int currentPos = pq.top().pos;
            int prevChangedPos = pq.top().lastChangedPos;
            int prevNumberOfChanges = pq.top().numberOfChanges;
            int prevNumberOfKJumps = pq.top().numberOfKJumps;
            pq.pop();

            if (currentPos == N)
                mn = min(prevNumberOfChanges, mn);

            int nextPos = currentPos + 1;
            if (nextPos <= N)
            {

                if (a[nextPos] != a[prevChangedPos])
                {
                    int nextKJumps = prevNumberOfKJumps + 1;
                    if (nextKJumps <= K) ///Don't change the current one => +1 K
                        pq.push({nextPos, nextPos, prevNumberOfChanges, nextKJumps});
                    ///Change current pos => +1 number of changes
                    pq.push({nextPos, prevChangedPos, prevNumberOfChanges + 1, prevNumberOfKJumps});
                    ///cout << nextPos << " " << prevNumberOfChanges + 1 << " " << prevNumberOfKJumps<< endl;
                }
                else ///Don't change anything
                {
                    ///
                    ///cout << a[prevChangedPos] << " " << a[nextPos] << endl;
                    ///cout << nextPos << " " << prevNumberOfChanges << " " << prevNumberOfKJumps<< endl;
                    pq.push({nextPos, prevChangedPos, prevNumberOfChanges, prevNumberOfKJumps});
                }

            }
        }
        cout << "Case #" << t << ": " << mn << endl;
    }
    return 0;
}
