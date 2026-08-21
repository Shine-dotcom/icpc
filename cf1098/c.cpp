#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int a, n;
    cin >> a >> n;
    vector<int> d(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> d[i];
    }
    int ans = 1e18;
    int t = a;
    bool flag = 1;
    int b = 0;
    while(t)
    {
        int dig = t % 10;
        bool flag1 = 0;
        for(int i = 1; i <= n; i ++ )
        {
            if(d[i] == dig) flag1 = 1;
        }
        flag &= flag1;
        t /= 10;
        if(flag) continue;
        b +=
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