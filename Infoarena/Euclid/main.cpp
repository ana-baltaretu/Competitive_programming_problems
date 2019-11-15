#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T, A, B;

int cmmdc(int a, int b)
{
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
    fin >> T;
    while (T--)
    {
        fin >> A >> B;
        fout << cmmdc(A, B) << "\n";
    }

    return 0;
}
