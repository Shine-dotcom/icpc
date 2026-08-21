#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int x, y, n;
    cin >> x >> y >> n;
    int flag = 0;
    pair<int, int> h[] = {{-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}};
    map<pair<int, int>, bool> mp;
    while(n -- )
    {
        int x0, y0;
        cin >> x0 >> y0;
        for(int i = 0; i < 8; i ++ )
        {
            mp[{x0 - h[i].first, y0 - h[i].second}] = 1;
        }
    }
    pair<int, int> d[] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    for(int i = 0; i < 8; i ++ )
    {
        if(mp[{x - d[i].first, y - d[i].second}] != 1)
        {
            flag = -1;
            break;
        }
    }
    if(flag == -1)
    {
        cout << "C" << endl;
        return;
    }
    if(flag == 0 && mp[{x, y}] == 1)
    {
        cout << "B" << endl;
        return;
    }
    cout << "A" << endl;
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
}
