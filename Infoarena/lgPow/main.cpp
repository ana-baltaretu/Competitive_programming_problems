#include <bits/stdc++.h>
#define MOD 1999999973
#define ll long long

using namespace std;

ifstream fin("lgput.in");
ofstream fout("lgput.out");

ll N, P;

ll lgPow(ll n, ll p)
{
    if (p == 0) return 1;
    if (p == 1) return n;
    if (p % 2 == 0)
    {
        ll temp = lgPow(n, p / 2);
        return (temp * temp) % MOD;
    }
    return (lgPow(n, p - 1) * n) % MOD;
}

int main()
{
    fin >> N >> P;
    fout << lgPow(N, P);
    return 0;
}
