#include <bits/stdc++.h>

using namespace std;

int T;

string pass, s, response;

int main()
{
    cin >> T;
    cin >> pass;
    bool ok = true;
    while (T--) {

        cin >> s >> response;
        int counter = 0;
        if (s.size() != pass.size()) {
            if (response == "ALLOWED") {
                ok = false;
            }
            continue;
        }
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != pass[i])
                cnt++;
        }

        if (cnt > 1 && response == "ALLOWED") {
            ok = false;
        }
        if (cnt < 2 && response == "DENIED") {
            ok = false;
        }

    }
    if (ok == true) {
        cout << "SYSTEM SECURE";
    } else cout << "INTEGRITY OVERFLOW";
    return 0;
}
