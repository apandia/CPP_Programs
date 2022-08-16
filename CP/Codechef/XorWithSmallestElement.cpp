//#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

// Perform XOR operation (X with smallest number in an array) y times

/*
Input:
3
1 6 99
9
3 7 44
1 2 3
5 20 6
5 10 15 20 25

Output:
15
3 5 6
5 20 25 27 30
*/

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;

    multiset<int> ms;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        ms.insert(tmp);
    }

    while (y > 0)
    {
        int a = *ms.begin();
        int b = a ^ x;

        // First b will in increasing order and once we found a lesser number, break
        if (b < a)
            break;

        ms.erase(ms.begin());
        ms.insert(b);

        y--;
    }

    if (y % 2 == 1)
    {
        //Only for odd number of y iteration remaining
        int a = *ms.begin();
        int b = a ^ x;

        ms.erase(ms.begin());
        ms.insert(b);
    }

    for (auto val : ms)
    {
        cout << val << " ";
    }
    cout << "\n";
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
