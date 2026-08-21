#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
vector<int> invfac[200011];
void shai()
{
    for(int i = 2; i <= 200010; i ++ )
    {
        if(invfac[i].empty())
        {
            for(int j = i; j <= 200010; j += i)
            {
                invfac[j].push_back(i);
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    int ans = 2;
    map<int, int> flag;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++ )
    {
        cin >> b[i];
    }
    for(int i = 1; i <= n; i ++ )
    {
        for(auto p : invfac[a[i]])
        {
            if(flag[p] > 0)
            {
                ans = 0;
            }
            flag[p] ++;
        }
    }
    for(int i = 1; i <= n; i ++ )
    {
        for(auto p : invfac[a[i]])
        flag[p] --;
        for(auto p : invfac[a[i] + 1])
        {
            if(flag[p] > 0)
            {
                ans = min(ans, 1ll);
            }
        }
        for(auto p : invfac[a[i]])
        flag[p] ++;
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    shai();
    // for(int i = 0; i < 20; i ++ )
    // {
    //     cout << prime[i] << endl;
    // }
    // cout << cnt << endl;
    while(t -- )
    {
        solve();
    }
}