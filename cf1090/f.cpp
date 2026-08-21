#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int x, y;
    cin >> x >> y;
    if(x > y || (x == 0 && y % 2 == 0))
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<pair<int, int>> e(x + y);
    for(int i = 1; i <= x + y - 1; i ++ )
    {
        e[i].first = i;
        e[i].second = i + 1;
    }
    int tmp = (y - x) / 2;
    for(int i = 0; i < tmp; i ++ )
    {
        e[x + y - 1 - 2 * i].first --;
    }
    for(int i = 1; i <= x + y - 1; i ++ )
    {
        cout << e[i].first << ' ' << e[i].second << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t -- )
    {
        solve();
    }
    return 0;
}