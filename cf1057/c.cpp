#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> cnt;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        cnt[a[i]] ++;
    }
    vector<int> v;
    int ans = 0;
    int cnt2 = 0;
    for(auto [x, c] : cnt)
    {
        ans += x * (c / 2 * 2);
        cnt2 += c / 2 * 2;
        c %= 2;
        if(c == 1)
        v.push_back(x);
    }
    // for(auto x : v)
    // {
    //     cout << x << ' ';
    // }
    // cout << endl;
    // int tmp = 0;
    if(v.size() == 0)
    {
        cout << ans << endl;
        return;
    }
    if(v.size() == 1)
    {
        if(v[0] >= ans && n == 3)
        {
            cout << 0 << endl;
            return;
        }
        if(v[0] >= ans)
        {
            cout << ans << endl;
            return;
        }
        cout << v[0] + ans << endl;
        return;
    }
    int ls = v.size();
    int res = ans;
    for(int i = ls - 2; i >= 0; i -- )
    {
        if(v[i + 1] - v[i] < ans)
        {
            res = max(v[i + 1] + v[i] + ans, res);
        }
        if(v[i + 1] < ans)
        {
            res = max(v[i + 1] + ans, res);
        }
        if(v[i] < ans)
        {
            res = max(v[i] + ans, res);
        }
    }
    if(cnt2 == 2 && res == ans)
    {
        cout << 0 << endl;
        return;
    }
    cout << res << endl;
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