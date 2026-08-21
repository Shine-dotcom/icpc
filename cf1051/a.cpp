#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), idx(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        idx[a[i]] = i;
    }
    int l = idx[n], r = idx[n];
    for(int i = 1; i < n; i ++ )
    {
        for(int j = l; j <= r; j ++ )
        {
            a[j] --;
        }
        int flag = 0;
        if(l > 1 || r < n)
        {
            if(l > 1 && a[l - 1] == a[l])
            {
                l --;
                flag = 1;
            }
            if(r < n && a[r + 1] == a[r])
            {
                r ++;
                flag = 1;
            }
            if(!flag)
            {
                // cout << l << ' ' << r << endl;
                cout << "NO" << endl;
                return;
            }
        }
        // for(int j = 1; j <= n; j ++ )
        // {
        //     cout << a[i] << ' ';
        // }
        // cout << endl;
    }
    cout << "YES" << endl;
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