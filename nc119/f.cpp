#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    int mx = -1, flag = 0;
    for(int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        cnt[x] ++;
    }
    // cout << "cnt:" << endl;
    // for(auto a : cnt)
    // {
    //     cout << a << ' ';
    // }
    // cout << endl;
    int res1 = 0;
    int idx;
    for(int i = 1; i < n; i ++ )
    {
        if(mx == cnt[i]) flag ++, idx = i;
        if(mx < cnt[i])
        {
            flag = 1;
            mx = cnt[i];
            idx = i;
        }
        if(cnt[i] >= cnt[n])
        res1 += cnt[i] - cnt[n] + 1;
    }
    // cout << "flag " << flag << endl;
    // cout << "idx " << idx << endl;
    // cout << "mx " << mx << endl;
    int res2 = 0;
    for(int i = n; i >= 1; i -- )
    {
        if(i == idx) break;
        res2 += cnt[i];
    }
    res2 += flag - 1;
    cout << min(res1, res2) << endl;
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