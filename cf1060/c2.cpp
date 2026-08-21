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
    map<int, int> flag;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++ )
    {
        cin >> b[i];
    }
    vector<int> ord(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        ord[i] = i;
    }
    sort(ord.begin() + 1, ord.end(), [&](int x, int y){
        return b[x] < b[y];
    });
    int ans = b[ord[1]] + b[ord[2]];
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
                ans = min(ans, b[i]);
            }
        }
        for(auto p : invfac[a[i]])
        flag[p] ++;
    }
    vector<int> check;
    int idx = ord[1];
    for(int i = 1; i <= n; i ++ )
    {
        if(i == idx) continue;

        for(auto p : invfac[a[i]])
        {
            check.push_back(p);
        }
    }
    for(auto p : check)
    {
        int times = p - (a[idx] % p);
        // cout << "333 " << times << endl;
        if(times == p)
        times = 0;
        ans = min(ans, times * b[idx]);
        // cout << "222 " << times << endl;
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