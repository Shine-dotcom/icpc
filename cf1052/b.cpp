#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<set<int>> st(n + 1);
    vector<int> cnt(m + 1);
    int res = n;
    for(int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        while(x -- )
        {
            int a;
            cin >> a;
            st[i].insert(a);
            cnt[a] ++;
        }
    }
    for(int i = 1; i <= m; i ++ )
    {
        if(cnt[i] == 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    for(int i = 1; i <= n; i ++ )
    {
        int flag = 0;
        for(auto x : st[i])
        {
            if(cnt[x] == 1) flag = 1;
        }
        res -= flag;
    }
    cout << (res >= 2 ? "YES" : "NO") << endl;
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