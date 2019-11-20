#include <bits/stdc++.h>
//#define NMAX 1005

using namespace std;

string input;

int main()
{
    cin >> input;
    int tabCount = 0, mx = 0, mxTabCount = 0;
    bool thisIsFile;
    vector<int> counter;
    counter.push_back(0);
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '\\' && input[i + 1] == 'n')
        {
            i++;
            tabCount = 0;
        }
        else if (input[i] == '\\' && input[i + 1] == 't')
        {
            thisIsFile = false;
            while (input[i] == '\\' && input[i + 1] == 't' && i < input.size())
            {
                i+=2;
                tabCount++;
                if (tabCount > mxTabCount)
                {
                    mxTabCount = tabCount;
                    counter.push_back(0);
                }
            }
            counter[tabCount] = counter[tabCount - 1];
            i--;
        }
        else if (input[i] == '.')
        {
            thisIsFile = true;
            counter[tabCount]++;
        }
        else counter[tabCount]++;

        if (thisIsFile)
            mx = max(mx, counter[tabCount] + tabCount);
    }
    cout << mx << endl;

    return 0;
}
