#include <bits/stdc++.h>

using namespace std;

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    int booked[20005] = {0};
    vector<int> answer;
    for (vector<vector<int>> :: iterator it = bookings.begin(); it != bookings.end(); it++)
    {
        vector<int> current = *it;
        int i = current[0], j = current[1], k = current[2];
        booked[i - 1] += k;
        booked[j] -= k;
    }
    int S = 0;
    for (int i = 0; i < n; i++)
    {
        S += booked[i];
        answer.push_back(S);
    }
    return answer;
}

vector<vector<int>> bookings;
vector <int> actual;

int main()
{

    actual.push_back(1);
    actual.push_back(2);
    actual.push_back(10);
    bookings.push_back(actual);
    for (vector<vector<int>> :: iterator it = bookings.begin(); it != bookings.end(); it++)
    {
        vector<int> current = *it;
        cout << current[0] << endl;
        cout << current[1] << endl;
        cout << current[2] << endl;
    }
    return 0;
}
