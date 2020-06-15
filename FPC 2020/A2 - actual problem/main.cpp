#include <bits/stdc++.h>
#define NMAX 505

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int n, m, k;
long long arr[NMAX][NMAX], newArr[NMAX][NMAX], newArr2[NMAX][NMAX], viz[NMAX][NMAX];

bool interior(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

void lee(int i, int j) {
    for (int d = 0; d < 4; d++) {
        int ii = i + dx[d];
        int jj = j + dy[d];
        if (interior(ii, jj) == true ) {
            if (newArr2[ii][jj] <= newArr2[i][j] && viz[ii][jj] > viz[i][j]) {
                viz[ii][jj] = viz[i][j];
                lee(ii, jj);
            } else if (newArr2[ii][jj] > newArr2[i][j] && viz[ii][jj] > newArr2[ii][jj] + 1) {
                viz[ii][jj] = max(newArr2[ii][jj] + 1, viz[i][j]);
                lee(ii, jj);
            }
        }
    }
}

int main()
{
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            viz[i][j] = LONG_MAX;
        }
    }

    for (int j = 0; j < m; j++) {
        deque<int> dq;

        for (int i = 0; i < k; i++) {
            while ((!dq.empty()) && arr[i][j] >= arr[dq.back()][j])
                dq.pop_back();
            dq.push_back(i);
        }

        for (int i = k; i < n; i++) {
            newArr[i - k][j] = arr[dq.front()][j];
            while ((!dq.empty()) && dq.front() <= i - k)
                dq.pop_front();
            while ((!dq.empty()) && arr[i][j] >= arr[dq.back()][j])
                dq.pop_back();
            dq.push_back(i);
        }
        for (int i = n - k; i < n; i++) {
            newArr[i][j] = arr[dq.front()][j];
        }
    }


    for (int i = 0; i < n; i++) {
        deque<int> dq;

        for (int j = 0; j < k; j++) {
            while ((!dq.empty()) && newArr[i][j] >= newArr[i][dq.back()])
                dq.pop_back();
            dq.push_back(j);
        }

        for (int j = k; j < m; j++) {
            newArr2[i][j - k] = newArr[i][dq.front()];
            while ((!dq.empty()) && dq.front() <= j - k)
                dq.pop_front();
            while ((!dq.empty()) && newArr[i][j] >= newArr[i][dq.back()])
                dq.pop_back();
            dq.push_back(j);
        }
        for (int j = m - k; j < m; j++) {
            newArr2[i][j] = newArr[i][dq.front()];
        }
    }


    viz[0][0] = newArr2[0][0] + 1;
    lee(0, 0);
    cout << viz[n - 1][m - 1];

    return 0;
}
