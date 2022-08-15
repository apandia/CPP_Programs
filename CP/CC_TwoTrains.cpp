#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    int numDistnace = n - 1;

    int totalTime = 0;
    int maxWaitTime = INT_MIN;

    vector<int> p(numDistnace, 0);
    for (int i = 0; i < numDistnace; i++)
    {
        cin >> p[i];
        totalTime += p[i];
        maxWaitTime = max(maxWaitTime, p[i]);
    }

    cout << totalTime + maxWaitTime << "\n";    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++)
    {
        solve();
    }

    return 0;
}
