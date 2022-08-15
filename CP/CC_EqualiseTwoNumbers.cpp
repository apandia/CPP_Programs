#include <iostream>

using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;

    if (a > b)
        swap(a, b);

    while (a < b)
    {
        a *= 2;
    }

    if (a == b)
        cout << "YES" << "\n";
    else
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
