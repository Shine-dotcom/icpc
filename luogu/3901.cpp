#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int blk;
struct query {
    int l, r, id;
    bool operator < (const query &u) const{
        if(l / blk != u.l / blk) return l < u.l;
        return ((l / blk) & 1 ? r < u.r : r > u.r);
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    blk = sqrt(n);
    vector<int> a(n + 1), cnt(n + 1), sum(n + 1);
    vector<query> qu(q + 1);
    int mx = 0;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    for(int i = 1; i <= q; i ++ ) cin >> qu[i].l >> qu[i].r, qu[i].id = i;
    sort(qu.begin() + 1, qu.end());
    vector<string> ans(q + 1);
    auto val = [&](int i) -> int {
        return i;
    };
    auto add = [&](int i) -> void {
        sum[++cnt[val(a[i])]]++;
        mx = max(mx, cnt[val(a[i])]);
    };
    auto del = [&](int i) -> void {
        if(sum[cnt[val(a[i])]] == 1 && mx == cnt[val(a[i])]) mx --;
        sum[cnt[val(a[i])]--]--;
    };
    for(int i = 1, l = 1, r = 0; i <= q; i ++ )
    {
        while(l > qu[i].l) add(--l);
        while(r < qu[i].r) add(++r);
        while(l < qu[i].l) del(l++);
        while(r > qu[i].r) del(r--);
        ans[qu[i].id] = (mx >= 2 ? "No" : "Yes");
    }
    for(int i = 1; i <= q; i ++ )
    {
        cout << ans[i] << endl;
    }
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