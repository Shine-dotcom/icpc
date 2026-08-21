#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<string> s(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = i + 1; j <= n; j ++ )
        {
            int res = 0;
            int m1 = s[i].size() - 1;
            int m2 = s[j].size() - 1;
            for(int k = -m2 + 1; k <= m1; k ++ )
            {
                int tmp = 0;
                for(int l = 1; l <= m2; l ++ )
                {
                    if(l + k <= 0) continue;
                    if(l + k > m1) continue;
                    if(s[i][l + k] == s[j][l])
                    {
                        tmp ++;
                        res = max(res, tmp);
                        continue;
                    }
                    tmp = 0;
                }
                res = max(tmp, res);
            }
            ans = max(ans, res);
        }
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
    return 0;
}