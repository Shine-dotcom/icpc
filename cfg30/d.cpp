#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s;
    cin >> t;
    s = " " + s;
    t = " " + t;
    vector<int> dis(n + 1);
    int mn = 0;
    for(int i = 2; i <= n; i ++ )
    {
        for(int j = 0; j <= min(i - 1, k); j ++ )
        {
            if(t[i] == s[i - j])
            {
                // cout << j << ' ' << mn << endl;
                mn = max(mn, j);
                dis[i] = j;
                break;
            }
            if(j == k)
            {
                mn = -1;
                break;
            }
        }
        if(mn == -1) break;
    }
    if(mn == -1 || mn == 0)
    {
        cout << mn << endl;
        return;
    }
    vector<string> ans;
    string s0 = s;
    for(int i = 1; i <= mn; i ++ )
    {
        for(int j = n; j >= 1; j -- )
        {
            if(dis[j])
            s0[j] = s0[j - 1];
        }
        ans.push_back(s0);
    }
    cout << mn << endl;
    for(int i = 0; i < mn; i ++ )
    {
        for(int j = 1; j <= n; j ++ )
        {
            cout << ans[i][j];
        }
        cout << endl;
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
}