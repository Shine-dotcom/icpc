#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin() + 1, b.end());
    int mid = b[(n + 1) >> 1];
    vector<int> cnt1(n + 1), cnt2(n + 1), cnt3(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cnt1[i] = cnt1[i - 1] + (a[i] < mid);
        cnt2[i] = cnt2[i - 1] + (a[i] == mid);
        cnt3[i] = cnt3[i - 1] + (a[i] > mid);
    }
    vector<int> dp(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = i - 1; j >= 0; j -= 2)
        {
            int c1 = cnt1[i] - cnt1[j];
            int c2 = cnt2[i] - cnt2[j];
            int c3 = cnt3[i] - cnt3[j];
            if(c1 + c2 > c3 && c2 + c3 > c1)
            {
                if(j && !dp[j]) continue;
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        // cout << dp[i] << ' ';
    }
    // cout << endl;
    cout << dp[n] << endl;
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