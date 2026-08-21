#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node{
    int a, b, idx;
};
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<node> seg(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> seg[i].a;
        seg[i].idx = i;
    }
    for(int i = 1; i <= n; i ++ )
    {
        cin >> seg[i].b;
    }
    
    vector<int> prel(n + 1), prer(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        prel[i] = (prel[i] > 0 ? prel[i - 1] : 0ll) + seg[i].a;
    }
    for(int i = n - 1; i >= 0; i -- )
    {
        prer[i + 1] = (prer[i + 1] > 0 ? prer[i] : 0ll) + seg[i].a;
    }
    int mx = -1e18;
    for(int i = 1, j = 0; i <= n; i ++ )
    {
        mx = max(mx, prel[i] + prer[i]);
        if(pre[i] < 0) j = i;
    }
    cout << mx << endl;
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