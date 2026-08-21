#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e5 + 10;
struct problem{
    char c;
    int sc, idx;
    bool operator < (const problem &u) const {
        if(c == u.c) return sc < u.sc;
        return c < u.c;
    }
} a[N];
int ans[10], sum;
void solve()
{
    int n;
    cin >> n;
    if(n < 6)
    {
        cout << -1 << endl;
        return;
    }
    for(int i = 1; i <= n; i ++ ) cin >> a[i].c >> a[i].sc, a[i].idx = i;
    sort(a + 1, a + n + 1);
    int cnt = 0;
    sum = 0;
    for(int i = 1; i <= n; i ++ )
    {
        if(i == n || a[i].c != a[i + 1].c)
        {
            ans[++ cnt] = i;
            sum += a[i].sc;
            if(a[i].sc < 60)
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    if(cnt < 6)
    {
        cout << -1 << endl;
        return;
    }
    if(sum < 420)
    {
        cout << -1 << endl;
        return;
    }
    for(int i = 1; i <= 6; i ++ )
    {
        cout << a[ans[i]].idx << ' ';
    }
    cout << endl;
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