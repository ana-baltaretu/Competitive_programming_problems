#include <bits/stdc++.h>
#define NMAX 505

using namespace std;

int n, k;
int arr[NMAX], newArr[NMAX];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    deque<int> dq;
    for (int i = 0; i < k; i++) {
        while ((!dq.empty()) && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    for (int i = k; i < n; i++) {
        newArr[i - k] = arr[dq.front()];
        while ((!dq.empty()) && dq.front() <= i - k)
            dq.pop_front();
        while ((!dq.empty()) && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);

    }

    for (int i = n - k; i < n; i++) {
        newArr[i] = arr[dq.front()];
    }


    for (int i = 0; i < n; i++)
        cout << newArr[i] << " ";




    return 0;
}
