#include <bits/stdc++.h>

using namespace std;

bool belowZero = true;
long long megaMX = LONG_MIN;

long long dfs(long long val, int children)
{
    if (val >= 0)
        belowZero = false;
    long long mx = 0, mx2 = 0;
    for (int i = 0; i < children; i++) {
        long long val2;
        int children2;
        cin >> val2 >> children2;
        long long r = dfs(val2, children2);
        if (r > mx){
            mx2 = mx;
            mx = r;
        }
        else if (r <= mx && r > mx2)
            mx2 = r;
    }
    if (val > megaMX)
        megaMX = val;
    if (mx + val > megaMX)
        megaMX = mx;
    if (mx2 + mx + val > megaMX)
        megaMX = mx2 + mx + val;
    return mx + val;
}

int main()
{
    int N;
    cin >> N;
    long long val;
    int children;
    cin >> val >> children;
    if (val >= 0)
        belowZero = false;
    if (val > megaMX)
        megaMX = val;
    long long answer = dfs(val, children);
    if (belowZero == true)
        cout << megaMX;
    else {
        if (megaMX > answer)
            cout << megaMX;
        else cout << answer;
    }
    return 0;
}
