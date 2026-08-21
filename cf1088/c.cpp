#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1), flag(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++ )
    {
        cin >> b[i];
    }
    set<int> sa, sb;
    for(int i = 1; i <= n; i ++ )
    {
        if(i >= n - k + 1 && i <= k)
        {
            sa.insert(a[i]);
            if(b[i] == -1) continue;
            sb.insert(b[i]);
        }
        if(b[i] == -1) continue;
        if(flag[b[i]] == 1)
        {
            cout << "NO" << endl;
            return;
        }
        if((i < n - k + 1 || i > k) && a[i] != b[i])
        {
            cout << "NO" << endl;
            return;
        }
        flag[b[i]] = 1;
    }
    for(auto x : sb)
    {
        if(sa.find(x) == sa.end())
        {
            cout << "NO" << endl;
            return;
        }
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
    return 0;
}