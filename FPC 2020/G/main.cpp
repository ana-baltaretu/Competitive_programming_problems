#include <bits/stdc++.h>

using namespace std;

long long cmmmc = 1;

long long cmmdc(long long a, long long b) {
    if (a % b == 0)
        return b;
    if (b % a == 0)
        return a;
    if (a > b)
        return cmmdc(a - a / b * b, b);
    return cmmdc(a, b - b / a * a);
}

int main()
{
    int n;
    long long a;
    cin >> n;
    while (n--) {
        cin >> a;
        long long cmmd = cmmdc(a, cmmmc);
        a = a / cmmd;
        cmmmc *= a;
    }
    cout << cmmmc;
    return 0;
}
