#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 50005;
int n, m, maxn;
int c[N];
int sum;
int cnt[N];
int ans1[N], ans2[N];

struct query {
    int l, r, id;

    bool operator < (const query &x) const {
        if(l / maxn != x.l / maxn) return l < x.l;
        return (l / maxn) & 1 ? r < x.r : r > x.r;
    }
} a[N];

void add(int i) {
    sum += cnt[i];
    cnt[i] ++;
}

void del(int i) {
    cnt[i] --;
    sum -= cnt[i];
}

void solve()
{
    cin >> n >> m;
    maxn = sqrt(n);
    for(int i = 1; i <= n; i ++ ) cin >> c[i];
    for(int i = 1; i <= m; i ++ ) cin >> a[i].l >> a[i].r, a[i].id = i;
    sort(a + 1, a + m + 1);
    for(int i = 1, l = 1, r = 0; i <= m; i ++ )
    {
        if(a[i].l == a[i].r) {
            ans1[a[i].id] = 0, ans2[a[i].id] = 1;
            continue;
        }
        while(l > a[i].l) add(c[--l]);
        while(r < a[i].r) add(c[++r]);
        while(l < a[i].l) del(c[l++]);
        while(r > a[i].r) del(c[r--]);
        ans1[a[i].id] = sum;
        ans2[a[i].id] = (r - l + 1) * (r - l) / 2;
    }
    for(int i = 1; i <= m; i ++ )
    {
        if(ans1[i])
        {
            int g = gcd(ans1[i], ans2[i]);
            ans1[i] /= g; ans2[i] /= g;
        }
        else
            ans2[i] = 1;
        cout << ans1[i] << '/' << ans2[i] << endl;
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
}