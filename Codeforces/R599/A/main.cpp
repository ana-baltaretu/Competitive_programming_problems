#include <bits/stdc++.h>
#define NMAX 1005

using namespace std;

int N, K;
int a[NMAX];

int main()
{
    cin >> K;
    while (K--)
    {
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> a[i];
        sort(a + 1, a + N + 1);
        int i = N, mx = 0;
        while (i > 0)
        {
            int current = min(N - i + 1, a[i]);
            mx = max(mx, current);
            i--;
        }
        cout << mx << "\n";
    }
    return 0;
}
