#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define x first
#define y second
const int mod = 998244353;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> seg(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> seg[i].x >> seg[i].y;
    }
    sort(seg.begin() + 1, seg.end(), [&](pair<int, int> u, pair<int, int> v){
        return (u.x == v.x ? u.y < v.y : u.x < v.x);
    });
    int ans = 1;
    for(int i = 1, j = 1; i <= n; i ++ )
    {
        while(j <= n && seg[i].y >= seg[j].x)
        {
            ans = (ans * (k -- )) % mod;
            j ++;
            if(k == -1)
            {
                cout << 0 << endl;
                return;
            }
        }
        k ++;
    }
    cout << ans << endl;
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