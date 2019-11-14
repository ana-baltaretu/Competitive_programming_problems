#include <bits/stdc++.h>

using namespace std;

int K, N;
string s1, s2;

bool checkMatch()
{
    if (s1.size() != s2.size())
        return false;
    int ok = 1;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i])
        {
            if (ok == 1)
                for (int j = i + 1; j < s2.size() && ok == 1; j++)
                {
                    if (s2[i] == s2[j] && s1[i] == s1[j])
                    {
                        swap(s1[i], s2[j]);
                        ok = 0;
                    }
                }
            else return false;
        }
    }
    if (s1 == s2) return true;
    return false;
}

int main()
{
    cin >> K;
    while (K--)
    {
        cin >> N >> s1 >> s2;
        if (checkMatch())
            cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
