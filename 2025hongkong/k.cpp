#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int mx = 0, mn = 1e18;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        mn = min(a[i], mn);
        mx = max(a[i], mx);
    }
    for(int i = 1; i <= n; i ++ ) a.push_back(a[i]);
    int l = 1;
    for(int i = 1, j = 1; i <= 2 * n; i ++ )
    {
        if(a[i] == mn)
        {
            if(a[j] != mn)
            {
                j = i;
                continue;
            }
            int mxi = mn, mxj = mn;
            for(int k = 1; k < 2 * n - i; k ++ )
            {
                mxi = max(mxi, a[i + k]);
                mxj = max(mxj, a[j + k]);
                if(mxi < mxj)
                {
                    j = i;
                    l = j;
                    break;
                }
            }
        }
    }
    vector<int> c(n + 1);
    for(int i = l; i <= l + n - 1; i ++ )
    {
        c[i - l + 1] = max(c[i - l], a[i]);
    }
    for(int i = 1; i <= n; i ++ )
    {
        cout << c[i] << ' ';
    }
    cout << endl;
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