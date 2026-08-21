#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    int cnt[2 * n + 1];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= 2 * n; i ++ )
    {
        int a;
        cin >> a;
        cnt[a] ++;
    }
    // for(int i = 1; i <= 2 * n; i ++ )
    // {
    //     cout << cnt[i] << ' ';
    // }
    // cout << endl;
    int ans = 0;
    for(int i = 1; i <= 2 * n; i ++ )
    {
        if(cnt[i] == 2 * n)
        {
            if(n % 2)
            {
                cout << 2 << endl;
                return;
            }
            cout << 0 << endl;
            return;
        }
    }
    int flag = 0;
    for(int i = 1; i <= 2 * n; i ++ )
    {
        if(cnt[i] & 1) ans ++, flag = 1;
    }
    int cnt0 = 0;
    for(int i = 1; i <= 2 * n; i ++ )
    {
        if(cnt[i] % 4 == 2)
        {
            ans += 2;
        }
        if(cnt[i] % 4 == 0 && cnt[i])
        {
            cnt0 ++;
        }
    }
    ans += (cnt0 / 2) * 4;
    if(flag && cnt0 % 2)
    {
        ans += 2;
    }
    cout << ans << endl;
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