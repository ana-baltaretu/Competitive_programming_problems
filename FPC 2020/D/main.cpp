#include <bits/stdc++.h>

using namespace std;

map <string, int> mp;

struct entry {
    string key;
    int val;

    bool operator < (const entry &other) const {
        if (val == other.val)
            return key > other.key;
        return val < other.val;
    }
};

int main()
{
    int N;
    cin >> N;
    string t1, t2;
    int s1, s2;
    for (int i = 0; i < N * (N - 1) / 2; i++) {
        cin >> t1 >> t2 >> s1 >> s2;
        if (s1 > s2) {
            mp[t1] += 3;
            mp[t2] += 0;
        } else if (s1 < s2) {
            mp[t2] += 3;
            mp[t1] += 0;
        } else {
            mp[t1] += 1;
            mp[t2] += 1;
        }
    }

    priority_queue<entry> pq;

    for (map<string, int> :: iterator it = mp.begin(); it != mp.end(); it++) {
        pq.push({it -> first, it -> second});
    }
    int cnt = 5;

    while (!pq.empty() && cnt > 0) {
        cout << pq.top().key << " " << pq.top().val << endl;
        pq.pop();
        cnt--;
    }
    return 0;
}
