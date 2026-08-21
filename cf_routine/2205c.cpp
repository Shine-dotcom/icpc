#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
bool c0[1000005];
struct node {
    int st, time, idx;
    bool operator < (const node &u) const {
        return time > u.time;
    }
};
struct node2 {
    int time, idx;
    bool operator < (const node &u) const {
        return time > u.time;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        memset(c0, 0, sizeof(c0));
        int l;
        cin >> l;
        vector<int> b(l + 1);
        for(int j = 1; j <= l; j ++ )
        {
            int x;
            cin >> x;
            cout << "x: " << x << ' ' << c0[x] << endl;
            if(c0[x]) cout << 111 << endl, b[c0[x]] = 0;
            c0[x] = j;
            b[j] = x;
        }
        for(int j = 1; j <= l; j ++ )
        {
            if(b[j]) a[i].push_back(b[j]);
        }
        reverse(begin(a[i]), end(a[i]));
    }
    sort(a.begin() + 1, a.end());
    // cout << endl;
    for(int i = 1; i <= n; i ++ )
    {
        for(auto x : a[i])
        {
            cout << x << ' ';
        }
        cout << endl;
    }
    cout << endl;
    vector<node> cnt(1000001);
    for(int i = 1; i <= 1e6; i ++ )
    {
        cnt[i].idx = i;
    }
    int c = 0;
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 0; j < a[i].size(); j ++ )
        {
            cnt[a[i][j]].st = 1;
            cnt[a[i][j]].time = ++ c;
        }
    }
    sort(cnt.begin() + 1, cnt.end());
    for(int i = 1; i <= c; i ++ )
    {
        if(cnt[i].st) cout << cnt[i].idx << ' ';
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