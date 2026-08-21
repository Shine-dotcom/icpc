#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> a(q);
    for(auto &x : a) cin >> x;
    int flagB = 0;
    for(int i = 0; i < n; i ++ )
    {
        if(s[i] == 'B')
        {
            flagB = 1;
            break;
        }
    }
    if(!flagB)
    {
        for(auto u : a)
        {
            cout << u << endl;
        }
        return;
    }
    for(auto u : a)
    {
        int t = u, cnt = 0, ans = 0;
        while(t)
        {
            if(s[cnt] == 'A')
            {
                t --;
                ans ++;
                cnt = (cnt + 1) % n;
                continue;
            }
            t >>= 1;
            cnt = (cnt + 1) % n;
            ans ++;
        }
        cout << ans << endl;
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