#include <bits/stdc++.h>
#define NMAX 55
#define pii pair <int, int>

using namespace std;

int K, N, cnt;
string s1, s2;
pii ans[NMAX];

bool swapChar(int i)
{
    for (int j = i + 1; j < s2.size(); j++)
    {
        if (s1[i] == s1[j])
        {
            swap(s1[i], s2[j]);
            ++cnt;
            ans[cnt].first = i;
            ans[cnt].second = j;
            return true;
        }
    }
    return false;
}

bool checkMatch()
{
    if (s1.size() != s2.size())
        return false;
    for (int i = 0; i < s1.size(); i++)
        if (s1[i] != s2[i])
            if (!swapChar(i))
                return false;
    if (s1 == s2) return true;
    return false;
}

int main()
{
    cin >> K;
    while (K--)
    {
        cin >> N >> s1 >> s2;
        cnt = 0;
        if (checkMatch())
        {
            cout << "Yes\n" << cnt << "\n";
            for (int i = 0; i < cnt; i++)
                cout << ans[i].first << " " << ans[i].second << "\n";
        }
        else cout << "No\n";
    }
    return 0;
}
