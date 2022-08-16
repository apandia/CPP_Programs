#include <bits/stdc++.h>

using namespace std;

// Solve the equation 2a+2b+ab = x where x will be given

/*
Input:
4   --> num TC
2
5
6
12

Output:
NO
YES
NO
YES
*/

void solve()
{
    int x;
    cin >> x;

    if (x < 5)
    {
        cout << "NO" << "\n";
        return;
    }

    for (int a = 1; a*a <= x; a++)
    {
        if ((x - 2 * a) % (2 + a) == 0)
        {
            cout << "YES" << "\n";
            return;
        }
    }

    cout << "NO" << "\n"; 
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
