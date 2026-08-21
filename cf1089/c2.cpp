#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
vector<int> prime;
void init()
{
    prime.push_back(1);
    for(int i = 2; i <= 100; i ++ )
    {
        if(prime.size() >= 21) break;
        int flag = 1;
        for(int j = 2; j * j <= i; j ++ )
        {
            if(i % j == 0) flag = 0;
        }
        if(flag)
        {
            prime.push_back(i);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++ )
    {
        cin >> b[i];
    }
    vector<int> c(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        int x = 1, y = 1;
        if(i > 1) y = __gcd(a[i], a[i - 1]);
        if(i < n) x = __gcd(a[i], a[i + 1]);
        c[i] = x * y / __gcd(x, y);
        if(c[i] > b[i]) c[i] = a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int> (21));
    for(int j = 0; j <= 20; j ++ )
    {
        if(prime[j] * c[1] > b[1]) break;
        int val = c[1] * prime[j];
        if(__gcd(val, c[2]) == __gcd(a[1], a[2]))
            dp[1][j] = (val != a[1]);
    }
    for(int i = 2; i < n; i ++ )
    {
        for(int j = 0; j <= 20; j ++ )
        {
            int x0 = __gcd(prime[j] * c[i], c[i + 1]);
            int y0 = __gcd(a[i], a[i + 1]);
            for(int k = 0; k <= 20; k ++ )
            {
                if(x0 != y0)
                {
                    dp[i][j] = max(dp[i - 1][k], dp[i][j]);
                    continue;
                }
                int x = __gcd(prime[j] * c[i], prime[k] * c[i - 1]);
                int y = __gcd(a[i], a[i - 1]);
                if(x == y)
                {
                    if(prime[j] * c[i] != a[i])
                    {
                        if(prime[j] * c[i] <= b[i])
                        {
                            dp[i][j] = max(dp[i - 1][k] + 1, dp[i][j]);
                        }
                    }
                }
                dp[i][j] = max(dp[i - 1][k], dp[i][j]);
            }
        }
    }
    for(int j = 0; j <= 20; j ++ )
    {
        for(int k = 0; k <= 20; k ++ )
        {
            int x = __gcd(prime[j] * c[n], prime[k] * c[n - 1]);
            int y = __gcd(a[n], a[n - 1]);
            if(x == y)
            {
                if(prime[j] * c[n] != a[n])
                {
                    if(prime[j] * c[n] <= b[n])
                    {
                        dp[n][j] = max(dp[n - 1][k] + 1, dp[n][j]);
                    }
                }
            }
            dp[n][j] = max(dp[n - 1][k], dp[n][j]);
        }
    }
    // for(int i = 0; i <= 20; i ++ )
    // {
    //     for(int j = 1; j <= n; j ++ )
    //     {
    //         cout << dp[j][i] << ' ';
    //     }
    //     cout << endl;
    // }
    int mx = 0;
    for(int j = 0; j <= 20; j ++ )
    {
        mx = max(mx, dp[n][j]);
    }
    cout << mx << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while(t -- )
    {
        solve();
    }
}