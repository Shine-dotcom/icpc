#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
// const int mod = 1e9 + 7;
vector<int> st(100010), prime(100010);
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> prifac(n + 1);
    for(int i = 2; i <= n; i ++ )
    {
        int t = i;
        while(t != 1)
        {
            for(int j = 0; prime[j] <= t; j ++ )
            {
                if(t % prime[j] == 0)
                {
                    prifac[i].push_back(prime[j]);
                    t /= prime[j];
                    break;
                }
            }
        }
    }
    // for(int i = 2; i <= n; i ++ )
    // {
    //     int ls = prifac[i].size();
    //     for(int j = 0; j < ls; j ++ )
    //     {
    //         cout << prifac[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    vector<vector<int>> dp(n + 1, vector<int> (30));
    vector<int> cnt(n + 1, 1);
    for(int i = 2; i <= n; i ++ )
    {
        int ls = prifac[i].size();
        dp[i][0] = 1;
        int t = 0;
        for(int j = 1; j < ls; j ++ )
        {
            if(prifac[i][j] != prifac[i][j - 1])
            {
                t = dp[i][j - 1];
                cnt[i] ++;
            }
            dp[i][j] = dp[i][j - 1] + t + 1;
        }
    }
    // for(int i = 2; i <= n; i ++ )
    // {
    //     int ls = prifac[i].size();
    //     // for(int j = 0; j < ls; j ++ )
    //     // {
    //     //     cout << dp[i][j] << ' ';
    //     // }
    //     cout << dp[i][ls - 1] - cnt[i];
    //     cout << endl;
    // }
    // cout << endl;
    vector<int> cnt2(n + 1);
    for(int i = 2; i <= n; i ++ )
    {
        int ls = prifac[i].size();
        cnt2[dp[i][ls - 1] - cnt[i]] ++;
    }
    vector<int> query;
    for(int i = 1; i <= m; i ++ )
    {
        int k;
        cin >> k;
        query.push_back(k);
    }
    for(auto x : query)
    {
        cout << cnt2[x] << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    int cnt = 0;
    for(int i = 2; i <= 100000; i ++ )
    {
        if(st[i] == 0) prime[cnt ++ ] = i;
        for(int j = 0; prime[j] <= 100000 / i; j ++ )
        {
            st[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    while(t -- )
    {
        solve();
    }
}