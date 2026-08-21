#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        int tmp = 100;
        for(int j = 0; j <= 15; j ++ )
        {
            for(int k = 0; k <= 15; k ++ )
            {
                int res = (a[i] + j) << k;
                if(res % (1 << 15) == 0)
                {
                    tmp = min(tmp, j + k);
                }
            }
        }
        ans[i] = tmp;
    }
    for(int i = 1; i <= n; i ++ )
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
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
    return 0;
}