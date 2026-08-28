#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct seg{
    int idx, h, cost, profit, flag;
    bool operator < (const seg &u) const{
        if(cost == u.cost) return flag > u.flag;
        return cost < u.cost;
    }
};
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<vector<int>> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        int m;
        cin >> m;
        for(int i = 1; i <= m; i ++ )
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
        for(int i = 1; i <= m; i ++ )
        {
            int x;
            cin >> x;
            b[i].push_back(x);
        }
    }
    vector<int> ans(n + 1);
    priority_queue<seg> val;
    auto cal = [&](int idx, int h) -> seg {
        int cnt = 0, mn = 1e18;
        while(h < a[idx].size() && cnt <= 0)
        {
            cnt -= a[idx][h];
            mn = min(mn, cnt);
            cnt += b[idx][h];
            h ++;
        }
        int flag = (cnt >= 0 ? 1 : 0);
        seg bu = {idx, h, abs(mn), cnt, flag};
        return bu;
    };
    for(int i = 1; i <= n; i ++ )
    {
        seg base = cal(i, 0);
        val.push(base);
    }
    // seg t = val.top();
    // while(x >= t.cost)
    // {
    //     x += t.profit;
    //     ans[t.idx] = t.h;
    //     if(t.h != a[t.idx].size()) val.push(cal(t.idx, t.h));
    //     t = val.top();
    // }
    // int mx = -1, idx = 0;
    // for(int i = 1; i <= n; i ++ )
    // {
    //     if(mx < ans[i])
    //     {
    //         idx = i;
    //         mx = ans[i];
    //     }
    // }
    // cout << mx << ' ' << idx << endl;
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