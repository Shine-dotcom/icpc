#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    vector<vector<int>> flag(411, vector<int> (14));
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    vector<int> cnt(415);
    vector<int> res(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        if(c[i] < 240 && flag[a[i]][b[i]] == 0)
        {
            res[i] = b[i];
        }
        else if(cnt[a[i]] < 3 && flag[a[i]][b[i]] == 0)
        {
            res[i] = b[i];
        }
        if(flag[a[i]][b[i]] == 0)
        {
            cnt[a[i]] ++;
            flag[a[i]][b[i]] = 1;
        }
    }
    for(int i = 1; i <= n; i ++ )
    {
        cout << res[i] << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t -- )
    {
        solve();
    }
}